/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:27:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/28 02:18:50 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/// @brief Try to set the capacity of the string to a given value.
/// @param str The string to set the capacity of.
/// @param min_growth The minimum growth of the capacity.
/// @return TRUE if the operation was successful, FALSE otherwise.
/// @warning Check the error flag for memory allocation errors.
t_bool	str_try_grow(t_str *str, size_t min_growth)
{
	size_t	new_capacity;

	new_capacity = (str_capacity(str) + min_growth) * FT_STR_GROW;
	return (str_try_set_capacity(str, new_capacity));
}

/// @brief Try to set the capacity of the string to a given value.
/// @param str The string to set the capacity of.
/// @note The capacity can't be less than FT_SMALL_STR.
/// @note This function can be used to free unused memory.
/// @return TRUE if the operation was successful, FALSE otherwise.
/// @warning Check the error flag for memory allocation errors.
t_bool	str_shrink_to_fit(t_str *str)
{
	size_t	fit_size;

	fit_size = str->len + 1;
	if (str_capacity(str) != fit_size)
		return (str_try_set_capacity(str, fit_size));
	return (TRUE);
}
