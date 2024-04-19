/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 03:04:08 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 03:09:10 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Reverse the order of the elements in the vec.
/// @param vec The vec to reverse.
void	vec_reverse(t_vec *vec)
{
	size_t	i;

	i = 0;
	while (i < vec->len / 2)
	{
		ft_memswap(vec_get_at(vec, i), vec_get_at(vec, vec->len - i - 1),
			vec->element_size);
		i++;
	}
}
