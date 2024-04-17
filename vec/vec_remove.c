/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:56:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 21:19:48 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Remove the last element from the vec.
/// @param vec  The vec to remove the element from.
void	vec_pop(t_vec *vec)
{
	if (vec->len)
		vec->len--;
}

/// @brief Remove the element at the given index from the vec.
/// @param vec The vec to remove the element from.
/// @param index The index of the element to remove.
void	vec_remove(t_vec *vec, size_t index)
{
	char	*buf;

	if (index >= vec->len)
		return ;
	buf = vec_get(vec);
	if (index + 1 < vec->len)
		ft_memmove(buf + index, buf + index + 1, (vec->len - index - 1)
			* vec->element_size);
	vec->len--;
}

/// @brief Remove elements in the range [start, end) from the vec.
/// @param vec The vec to remove elements from.
/// @param start The start index of the range.
/// @param end The end index of the range.
void	vec_remove_range(t_vec *vec, size_t start, size_t end)
{
	char	*buf;

	if (start >= vec->len || end <= start)
		return ;
	end = ft_umin(end, vec->len);
	buf = vec_get(vec);
	if (end < vec->len)
		ft_memmove(buf + start, buf + end, (vec->len - end)
			* vec->element_size);
	vec->len -= end - start;
}

/// @brief Remove the last 'n' elements from the vec.
/// @param vec The vec to remove elements from.
/// @param n The number of elements to remove.
void	vec_trunc(t_vec *vec, size_t n)
{
	vec->len -= ft_umin(n, vec->len);
}

/// @brief Remove all elements from the vec.
/// @param vec The vec to remove all elements from.
/// @note Resets the 'mem_err' flag.
void	vec_clear(t_vec *vec)
{
	vec->len = 0;
	vec->mem_err = FALSE;
}
