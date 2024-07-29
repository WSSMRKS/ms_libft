/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:21 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/18 21:37:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# pragma once

# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_state
{
	char	*buf;
	char	*buf_pos;
	ssize_t	remaining;
	int		fd;
}			t_state;

char		*_get_next_line(int fd, t_bool destroy);
char		*get_next_line(int fd);
void		get_next_line_finish(int fd);

void		del_state(void *content);
t_state		*new_state(int fd);
char		*read_into_buf(t_state *st);
char		*new_str_fill_back(char *str, size_t str_len, size_t new_len);
size_t		len_until_nl(char *str, size_t str_len);

#endif
