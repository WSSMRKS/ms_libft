/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:54:05 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 23:02:22 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Checks if the given vec is identical to another vec.
/// Vecs can be equal but not be identical
/// if the data location is different.
/// @param vec1
/// @param vec2
/// @return TRUE if the vecs are identical, FALSE otherwise.
t_bool	vec_identical(const t_vec *vec1, const t_vec *vec2)
{
	if (vec1->element_size != vec2->element_size)
		return (FALSE);
	if (vec1->len != vec2->len)
		return (FALSE);
	if (vec1->heap && vec2->heap)
		return (vec1->_large_buf == vec2->_large_buf);
	if (!vec1->heap && !vec2->heap)
		return (ft_memcmp(vec1->_small_buf, vec2->_small_buf, vec1->len
				* vec1->element_size) == 0);
	return (FALSE);
}

/// @brief Checks if the given vec is equal to another vec.
/// @param vec1
/// @param vec2
/// @return TRUE if the vecs are equal, FALSE otherwise.
t_bool	vec_cmp(const t_vec *vec1, const t_vec *vec2)
{
	if (vec1->element_size != vec2->element_size)
		return (FALSE);
	if (vec1->len != vec2->len)
		return (FALSE);
	if (vec1->heap && vec2->heap)
		return (vec1->_large_buf == vec2->_large_buf);
	return (ft_memcmp(vec_get(vec1), vec_get(vec2),
			vec1->len * vec1->element_size) == 0);
}
