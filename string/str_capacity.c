/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:48:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 22:03:47 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static void	heap_arr_to_stack_arr(t_str *str)
{
	char	*temp;

	temp = str->_large_string;
	ft_strlcpy(str->_small_string, temp, FT_SMALL_STR);
	str->len = ft_umin(str->len, FT_SMALL_STR - 1);
	str->heap = FALSE;
	free(temp);
}

static t_bool	stack_arr_to_heap_arr(t_str *str, size_t capacity)
{
	char	*temp;

	temp = malloc(capacity);
	if (temp == 0)
		return (FALSE);
	ft_strlcpy(temp, str->_small_string, capacity);
	str->_large_string = temp;
	str->heap = TRUE;
	return (TRUE);
}

static t_bool	resize_heap_arr(t_str *str, size_t n)
{
	char	*temp;

	temp = ft_reallocstring(str->_large_string, n);
	if (temp == 0)
		return (FALSE);
	free(str->_large_string);
	str->_large_string = temp;
	return (TRUE);
}

/// @brief Changes the capacity of the string.
/// @param str String to change the capacity of.
/// @param n New capacity.
/// @note The capacity can't be less than FT_SMALL_STR.
/// @return TRUE if the operation was successful, FALSE otherwise.
/// @warning Check the error flag for memory allocation errors.
t_bool	str_try_set_capacity(t_str *str, size_t n)
{
	t_bool	success;

	success = TRUE;
	n = ft_umax(n, FT_SMALL_STR);
	if (n == FT_SMALL_STR)
	{
		if (str->heap)
			heap_arr_to_stack_arr(str);
	}
	else if (!str->heap)
		success = stack_arr_to_heap_arr(str, n);
	else
		success = resize_heap_arr(str, n);
	if (success)
	{
		if (str->heap)
			str->_capacity = n;
		str->len = ft_umin(str->len, n - 1);
	}
	else
		str->mem_err = TRUE;
	return (success);
}

/// @brief Get the capacity of the string.
/// @param str String to get the capacity of.
/// @return The capacity of the string.
size_t	str_capacity(t_str str)
{
	if (str.heap)
		return (str._capacity);
	return (FT_SMALL_STR);
}
