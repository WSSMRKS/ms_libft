/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:17:21 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 19:42:32 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "../libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_state
{
	char	*buf;
	char	*buf_pos;
	ssize_t	remaining;
	int		fd;
}	t_state;

char	*get_next_line(int fd);

void	del_state(void *content);
t_state	*new_state(int fd);
char	*read_into_buf(t_state *st);
char	*str_create_fill_back(char *str, size_t str_len, size_t new_len);
size_t	len_until_nl(char *str, size_t str_len);

#endif
