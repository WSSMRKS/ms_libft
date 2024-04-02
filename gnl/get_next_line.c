/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:24 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:53:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Creates a new string holding an entire line read from the file descriptor.
 * Returns 0 if a malloc failed or a read errored.
 * Returns string with length 'len' if the file descriptor is at EOF (needed for
 * the deeper recursive calls to next_line to fill in their parts of the line).
 *
 * Example with (file = "AB" & BUFFER_SIZE = 1)
 *
 * at depth 2 -> new_str_fill_back(str = "", str_len = 0, new_len = 2)
 * |  depth  |  len  |  buf  |->|  depth  |  str   |
 * |:-------:|:-----:|:-----:|--|:-------:|:------:|
 * |    0    |   0   |   A   |->|    2    |  --\0  |
 * |    1    |   1   |   B   |->|    1    |  -B\0  |
 * |    2    |   2   |   -   |->|    0    |  AB\0  |
 *
 * Example with (file = "ABC\n" & BUFFER_SIZE = 2)
 *
 * at depth 1 -> new_str_fill_back(str = "C\n", str_len = 2, new_len = 4)
 * |  depth  |  len  |  buf  |->|  depth  |    str    |
 * |:-------:|:-----:|:-----:|--|:-------:|:---------:|
 * |    0    |   0   |  AB   |->|    1    |  --C\n\0  |
 * |    1    |   2   |  C\n  |->|    0    |  ABC\n\0  |
*/
unsigned char	*next_line(t_state *st, size_t len)
{
	t_state	st_cpy;
	size_t	nl_len;
	unsigned char	*str;

	if ((!st->remaining || !st->buf) && !read_into_buf(st) && st->remaining < 0)
		return (0);
	else if (!st->remaining)
		return (new_str_fill_back(0, 0, len));
	nl_len = len_until_nl(st->buf_pos, st->remaining);
	st->remaining -= nl_len;
	st->buf_pos += nl_len;
	if (nl_len)
		return (new_str_fill_back(st->buf_pos - nl_len, nl_len, len + nl_len));
	st_cpy = *st;
	st->buf = 0;
	str = next_line(st, len + st_cpy.remaining);
	if (str)
		ft_memcpy(str + len, st_cpy.buf_pos, st_cpy.remaining);
	free(st_cpy.buf);
	return (str);
}

t_list	*new_state_node(int fd)
{
	t_list	*out;
	t_state	*state;

	state = new_state(fd);
	if (!state)
		return (0);
	out = ft_lstnew(state);
	if (!out)
		del_state(state);
	return (out);
}

t_bool	match_fd(t_list *node, void *fd)
{
	return (((t_state *)(node->content))->fd == *(int *)fd);
}

unsigned char	*get_next_line(int fd)
{
	static t_list			*list;
	t_list					*state;
	unsigned char			*out;

	state = ft_lstswp_front_where(&list, match_fd, &fd);
	if (!state)
	{
		state = new_state_node(fd);
		if (!state)
			return (0);
		ft_lstadd_front(&list, state);
	}
	((t_state *) state->content)->fd = fd;
	out = next_line(state->content, 0);
	if (out && *out)
		return (out);
	ft_lstdel_first(&list, del_state);
	if (out && !*out)
		free(out);
	return (0);
}
