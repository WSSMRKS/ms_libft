/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:15 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/18 21:55:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

size_t	str_count(const t_str *str, size_t (*count)(const char *))
{
	size_t		out;
	size_t		i;
	const char	*buf;

	i = 0;
	out = 0;
	buf = cstr_ref(str);
	while (i < str->len)
		out += count(buf + i++);
	return (out);
}

t_bool	str_contains(const t_str *str, t_bool (*test)(const char *))
{
	size_t		i;
	const char	*buf;

	i = 0;
	buf = cstr_ref(str);
	while (i < str->len)
	{
		if (test(buf + i++))
			return (true);
	}
	return (false);
}

t_bool	str_find(const t_str *str, t_bool (*test)(const char *), size_t *at)
{
	size_t		i;
	const char	*buf;

	i = 0;
	buf = cstr_ref(str);
	while (i < str->len)
	{
		if (test(buf + i))
		{
			*at = i;
			return (true);
		}
		i++;
	}
	return (false);
}
