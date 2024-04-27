/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:53:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/27 05:09:39 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	vec_display(t_vec *vec, t_str (*display)(const void *))
{
	t_str	out;
	size_t	i;

	out = str_new_clone("[");
	i = 0;
	while (i < vec->len)
	{
		str_pushstr2(&out, display(vec_get_at(vec, i)));
		if (i + 1 < vec->len)
			str_pushstr(&out, ", ");
		++i;
	}
	str_pushstr(&out, "]");
	return (out);
}

t_str	vec_debug(t_vec *vec, t_str (*debug)(const void *))
{
	t_str	out;
	size_t	i;

	out = str_new_clone("{len=");
	str_itoa_append(vec->len, str_base10(), &out);
	str_pushstr(&out, " cap=");
	str_itoa_append(vec_capacity(vec), str_base10(), &out);
	if (vec->mem_err)
		str_pushstr(&out, " !mem_err!");
	str_pushstr(&out, " [");
	i = 0;
	while (i < vec->len)
	{
		str_pushstr2(&out, debug(vec_get_at(vec, i)));
		if (i + 1 < vec->len)
			str_pushstr(&out, ", ");
		++i;
	}
	str_pushstr(&out, "]}");
	return (out);
}
