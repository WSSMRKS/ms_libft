/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_str2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:01:28 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/14 12:49:50 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	map_str_to_str_slice(const void *from, void *to)
{
	*(t_str_slice *)to = str_view(from);
}

/// @brief Transforms a vec of strings to a vec of string slices.
/// @param strs Vec of strings.
/// @param out Vec of string slices.
/// @warning `out` may *NOT* be an alias of `strs`,
/// @return True if successful, false otherwise.
t_bool	vec_strs_to_str_slices(const t_vec *strs, t_vec *out)
{
	*out = vec_map(strs, map_str_to_str_slice, sizeof(char *));
	if (out->mem_err)
	{
		vec_destroy(out, 0);
		return (false);
	}
	return (true);
}
