/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:16:30 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:22:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_insert(t_str *str, size_t index, char c)
{
	str_insertn(str, index, c, 1);
}


void	str_insertn(t_str *str, size_t index, char c, size_t n)
{
	char	*buf;

	if (index > str->len)
		return (0);
	if (str->len + n >= str->capacity)
		str_grow(str, n);
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	ft_memset(buf + index, c, n);
	str->len += n;
}

void	str_insertstr(t_str *str, size_t index, const char *s)
{
	str_insertstrn(str, index, s, ft_strlen(s));
}

void	str_insertstrn(t_str *str, size_t index, const char *s, size_t n)
{
	char	*buf;

	if (index > str->len)
		return (0);
	if (str->len + n >= str->capacity)
		str_grow(str, n);
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	buf = buf + index;
	str->len += n;
	while (*s && n--)
		*buf++ = *s++;
}
