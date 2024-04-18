/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pushstr2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:01 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 16:03:07 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Append a string to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr2(t_str *str, t_str s)
{
	str_pushstr2_sized(str, s, s.len);
}

/// @brief Append a string to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @param len Length of the string to append.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr2_sized(t_str *str, t_str s, size_t len)
{
	str_pushstrn2_sized(str, s, len, s.len);
}

/// @brief Append a string to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @param n Number of times to append the string.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn2(t_str *str, t_str s, size_t n)
{
	str_pushstrn2_sized(str, s, s.len, n);
}

/// @brief Append a string to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @param len Length of the string to append.
/// @param n Number of times to append the string.
/// @note Unoptimized (TODO)
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn2_sized(t_str *str, t_str s, size_t len, size_t n)
{
	while (n--)
		str_insertstr_sized(str, str->len, str_get(&s), len);
}
