/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:48:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 17:06:09 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include <stdlib.h>

static void	heap_arr_to_stack_arr(t_vec *vec)
{
	void	*temp;

	temp = vec->_large_buf;
	vec->heap = false;
	vec->len = ft_umin(vec->len, vec_capacity(vec));
	ft_memcpy(vec->_small_buf, temp, vec->len * vec->element_size);
	free(temp);
}

static t_bool	stack_arr_to_heap_arr(t_vec *vec, size_t capacity)
{
	void	*temp;

	temp = malloc(capacity * vec->element_size);
	if (temp == 0)
		return (false);
	ft_memcpy(temp, vec->_small_buf, vec->len * vec->element_size);
	vec->_large_buf = temp;
	vec->heap = true;
	return (true);
}

static t_bool	resize_heap_arr(t_vec *vec, size_t capacity)
{
	void	*temp;

	temp = ft_reallocarray(vec->_large_buf, vec->len, capacity,
			vec->element_size);
	if (temp == 0)
		return (false);
	free(vec->_large_buf);
	vec->_large_buf = temp;
	return (true);
}

/// @brief Changes the capacity of the vec.
/// @param vec Vec to change the capacity of.
/// @param n New capacity.
/// @note The capacity can't be less than `FT_SMALL_VEC`.
/// @warning Check the error flag for memory allocation errors.
/// @return true if the operation was successful, false otherwise.
t_bool	vec_try_set_capacity(t_vec *vec, size_t n)
{
	t_bool	success;
	t_bool	to_stack;

	success = ft_safe_umult(n, vec->element_size, ~(size_t)0);
	if (success)
	{
		to_stack = n <= FT_SMALL_VEC / vec->element_size;
		if (vec->heap && to_stack)
			heap_arr_to_stack_arr(vec);
		else if (!to_stack && !vec->heap)
			success = stack_arr_to_heap_arr(vec, n);
		else if (!to_stack && vec->heap)
			success = resize_heap_arr(vec, n);
		if (success)
		{
			if (vec->heap)
				vec->_capacity = n;
			vec->len = ft_umin(vec->len, n);
		}
		else
			vec->mem_err = true;
	}
	return (success);
}

/// @brief Returns the capacity of the vec.
/// @param vec Vec to get the capacity of.
/// @return The capacity of the vec.
size_t	vec_capacity(const t_vec *vec)
{
	if (vec->heap)
		return (vec->_capacity);
	return (FT_SMALL_VEC / vec->element_size);
}
