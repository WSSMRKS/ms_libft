/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_fold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 05:56:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/27 05:09:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	iter_total_len(t_vec *vec, size_t i, void *total_len)
{
	*(size_t *)total_len += ((t_str *)vec_get_at(vec, i))->len;
}

t_str	vec_join_strs(const t_vec *vec, const t_str *seperator)
{
	t_str	*strs;
	t_str	out;
	size_t	total_len;
	size_t	i;

	total_len = 0;
	if (seperator && vec->len > 1)
		total_len += (vec->len - 1) * seperator->len;
	vec_iteri((t_vec *)vec, iter_total_len, &total_len);
	out = str_empty_with_capacity(total_len + 1);
	i = 0;
	strs = vec_get(vec);
	while (i < vec->len)
	{
		str_cat(&out, strs[i]);
		if (seperator && i + 1 < vec->len)
			str_cat(&out, *seperator);
		++i;
	}
	return (out);
}

size_t			vec_count(const t_vec *vec, size_t (*count)(const void *))
{
	size_t	out;
	size_t	i;

	i = 0;
	out = 0;
	while (i < vec->len)
		out += count(vec_get_at(vec, i++));
	return (out);
}

t_bool			vec_contains(const t_vec *vec, t_bool (*test)(const void *))
{
	size_t	i;

	i = 0;
	while (i < vec->len)
	{
		if (test(vec_get_at(vec, i)))
			return (TRUE);
		++i;
	}
	return (FALSE);
}