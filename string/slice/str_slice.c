/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_slice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:15:30 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 14:38:22 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_slice.h"

/// @brief Creates a stringview from a cstr.
/// @param str The string to view.
/// @return The stringview.
t_str_slice	cstr_view(const char *str)
{
	return ((t_str_slice){.len = ft_strlen(str), .str = str});
}

/// @brief Creates a stringview from a cstr.
/// @param str The string to view.
/// @param len The length of the stringview.
/// @return The stringview.
/// @warning The length of the stringview is not checked.
t_str_slice	cstr_slice(const char *str, size_t len)
{
	return ((t_str_slice){.len = len, .str = str});
}

/// @brief Creates a stringview from a string.
/// @param str The string to view.
/// @return The stringview.
t_str_slice	str_view(const t_str *str)
{
	return ((t_str_slice){.len = str->len, .str = cstr_ref(str)});
}

/// @brief Creates a stringview from a string.
/// @param str The string to view.
/// @param start The start index of the view.
/// @param end The end index of the view.
/// @return The stringview.
t_str_slice	str_slice(const t_str *str, size_t start, size_t end)
{
	start = ft_umin(start, str->len);
	end = ft_umax(start, ft_umin(end, str->len));
	return ((t_str_slice){.len = end - start, .str = cstr_ref(str) + start});
}
