/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:02:06 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 05:27:48 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Destroy the vec and free the memory.
/// @param vec The vec to destroy.
/// @param destroy (Null)Pointer to function to call for each element.
/// @note The vec will be empty, but still usable after this operation.
void	vec_destroy(t_vec *vec, t_vec_iter destroy)
{
	if (destroy)
		vec_iter(vec, destroy);
	if (vec->heap)
	{
		free(vec->_large_buf);
		vec->heap = FALSE;
	}
	vec->len = 0;
	vec->mem_err = FALSE;
}
