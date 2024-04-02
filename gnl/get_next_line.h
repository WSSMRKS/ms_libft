/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:21 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:54:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_state
{
	unsigned char	*buf;
	unsigned char	*buf_pos;
	ssize_t			remaining;
	int				fd;
}	t_state;

unsigned char	*get_next_line(int fd);

void			del_state(void *content);
t_state			*new_state(int fd);
unsigned char	*read_into_buf(t_state *st);
unsigned char	*new_str_fill_back(unsigned char *str, size_t str_len, size_t new_len);
size_t			len_until_nl(unsigned char *str, size_t str_len);

#endif
