/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:16:30 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:56:02 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_insert(t_str *str, size_t index, unsigned char c)
{
	str_insertn(str, index, c, 1);
}


void	str_insertn(t_str *str, size_t index, unsigned char c, size_t n)
{
	unsigned char	*buf;
	size_t			cap;

	if (index > str->len)
		return;
	cap = str_capacity(*str);
	if (str->len + n >= cap)
		str_grow(str, str->len + n - cap);
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	ft_memset(buf + index, c, n);
	str->len += n;
}

void	str_insertstr(t_str *str, size_t index, const unsigned char *s)
{
	str_insertstrn(str, index, s, ft_strlen(s));
}

void	str_insertstrn(t_str *str, size_t index, const unsigned char *s, size_t n)
{
	unsigned char	*buf;
	size_t			cap;

	if (index > str->len)
		return;
	cap = str_capacity(*str);
	if (str->len + n >= cap)
		str_grow(str, str->len + n - cap);
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	buf = buf + index;
	str->len += n;
	while (*s && n--)
		*buf++ = *s++;
}
