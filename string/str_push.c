/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:27:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:07:27 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_push(t_str *str, char c)
{
	char	*buf;

	if (str->len + 1 >= str->capacity)
		str_grow(str, 1);
	buf = str_get(str);
	buf[str->len++] = c;
	buf[str->len] = 0;
}

void	str_pushn(t_str *str, char c, size_t n)
{
	char	*buf;

	if (str->len + n >= str->capacity)
		str_grow(str, n);
	buf = str_get(str);
	while (n--)
		buf[str->len++] = c;
	buf[str->len] = 0;
}

void	str_pushstr(t_str *str, const char *s)
{
	char	*buf;

	buf = str_get(str);
	while (str->len + 1 < str->capacity && *s)
	{
		buf[str->len++] = *s++;
	}
	buf[str->len] = 0;
	if (*s)
	{
		str_grow(str, ft_strlen(s));
		str_pushstr(str, s);
	}
}

void	str_pushstrn(t_str *str, const char *s, size_t n)
{
	if (str->len + n >= str->capacity)
		str_grow(str, n);
	str_pushstr(str, s);
}
