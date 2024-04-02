/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:27:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:05:35 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_push(t_str *str, char c)
{
	char	*buf;

	if (str->len + 1 >= str_capacity(*str))
		str_grow(str, 1);
	buf = str_get(str);
	buf[str->len++] = c;
	buf[str->len] = 0;
}

void	str_pushn(t_str *str, char c, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*str);
	if (str->len + n >= cap)
		str_grow(str, str->len + n - cap);
	buf = str_get(str);
	while (n--)
		buf[str->len++] = c;
	buf[str->len] = 0;
}

void	str_pushstr(t_str *str, const char *s)
{
	char	*buf;

	buf = str_get(str);
	while (*s && str->len + 1 < str_capacity(*str))
	{
		buf[str->len++] = *s++;
	}
	buf[str->len] = 0;
	if (*s)
	{
		str_grow(str, ft_strlen(s));
		// TODO fix infinite recursion when str_grow is not able to grow
		str_pushstr(str, s);
	}
}

void	str_pushstrn(t_str *str, const char *s, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*str);
	if (str->len + n >= cap)
		str_grow(str, str->len + n - cap);
	buf = str_get(str);
	while (*s && n--)
		buf[str->len++] = *s++;
	buf[str->len] = 0;
}
