/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:20:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*buf;
	size_t		i;

	buf = s;
	i = 0;
	while (i < n && buf[i] != (char)c)
		i++;
	if (i == n)
		return (0);
	return ((void *)&buf[i]);
}
