/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pushstr2_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:04:01 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 16:07:37 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Insert a string at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr2_front(t_str *str, t_str s)
{
	str_insertstr(str, 0, str_get(&s));
}

/// @brief Insert a string n times at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @param n The number of times to insert the string.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn2_front(t_str *str, t_str s, size_t n)
{
	str_insertstrn(str, 0, str_get(&s), n);
}

/// @brief Insert a string of a given max size at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @param n The max size of the string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr2_sized_front(t_str *str, t_str s, size_t len)
{
	str_insertstr_sized(str, 0, str_get(&s), len);
}

/// @brief Insert a string of a given max size at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @param n The max size of the string to insert.
/// @note Unoptimized (TODO)
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn2_sized_front(t_str *str, t_str s, size_t len, size_t n)
{
	while (n--)
		str_insertstr_sized(str, 0, str_get(&s), len);
}
