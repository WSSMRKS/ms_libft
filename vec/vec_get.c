/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:11:36 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 00:43:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Gives read access to the vec data.
/// @param vec Vec to read from.
/// @return Pointer to the vec data.
void	*vec_get(const t_vec *vec)
{
	if (vec->heap)
		return (vec->_large_buf);
	return ((void *)vec->_small_buf);
}

/// @brief Destroys the given vec and returns its data.
/// @param vec Vec to destroy.
/// @return Pointer to the vec data or null.
/// @note Might need to malloc if the data is on the stack.
void	*vec_take(t_vec *vec)
{
	char	*out;

	if (vec->heap)
		out = vec->_large_buf;
	else
		out = ft_memdup(vec->_small_buf, vec->len * vec->element_size);
	*vec = vec_empty(vec->element_size);
	return (out);
}

/// @brief Clones the data of the given vec.
/// @param vec Vec to clone.
/// @return Pointer to the cloned vec data or null.
void	*vec_get_cloned(const t_vec *vec)
{
	return (ft_memdup(vec_get(vec), vec->len * vec->element_size));
}
