/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:19:21 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 23:52:33 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static t_str_view	split_next(t_str *str, size_t *i, t_str_pattern pattern)
{
	t_str_view	out;
	char		*buf;
	size_t		matched;

	buf = str_get(str);
	while (*i < str->len)
	{
		matched = pattern(buf + *i);
		*i += matched;
		if (matched == 0)
			break ;
	}
	out = str_new_from_parts(buf + *i, 0);
	while (*i < str->len && !pattern(buf + *i))
	{
		out.len++;
		(*i)++;
	}
	return (out);
}

/// @brief Splits a string into a vec of `t_str_view`.
/// @param str The string to split.
/// @param pattern The pattern to split the string at.
/// @return A vec of stringviews.
/// @warning Check the error flag for memory allocation errors.
t_vec	str_split(const t_str *str, t_str_pattern pattern)
{
	t_vec		out;
	t_str_view	next;
	size_t		i;

	i = 0;
	out = vec_empty(sizeof(t_str));
	while (i < str->len)
	{
		next = split_next((t_str *)str, &i, pattern);
		vec_push(&out, &next);
	}
	if (out.len > 0 && ((t_str_view *)vec_get_last(&out))->len == 0)
		vec_remove_last(&out);
	return (out);
}
