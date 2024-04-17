/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:33:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 00:42:43 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Clones a vec.
/// @param vec Vec to clone.
/// @return A new vec with the same content as the original.
/// @warning Check the error flag for memory allocation errors.
t_vec	vec_clone(const t_vec *vec)
{
	return (vec_new_clone(vec_get(vec), vec->len, vec->element_size));
}

/// @brief Clones a vec with a new length.
/// @param vec Vec to clone.
/// @param new_len New length of the cloned vec.
/// @return A new vec with the same content as the original.
/// @warning Check the error flag for memory allocation errors.
t_vec	vec_clone_sized(const t_vec *vec, size_t new_len)
{
	return (vec_new_clone(vec_get(vec), ft_umin(vec->len, new_len),
			vec->element_size));
}
