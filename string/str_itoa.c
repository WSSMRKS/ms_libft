/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:16:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 17:05:16 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/// @brief Converts an integer to a string and appends it to the output string.
/// @param num The integer to convert.
/// @param base The base to use for the conversion.
/// @param out The output string.
/// @warning Check the error flag for memory allocation errors.
static void	_str_itoa_recursive(unsigned int num, t_str_slice base, t_str *out)
{
	if (num >= base.len)
		_str_itoa_recursive(num / base.len, base, out);
	str_push(out, base.str[num % base.len]);
}

static void	_str_itoa(int num, t_str_slice base, t_str *out)
{
	if (num == INT_MIN)
		str_pushstr(out, cstr_slice("-2147483648", 11));
	else if (num < 0)
	{
		str_push(out, '-');
		_str_itoa_recursive(-num, base, out);
	}
	else
		_str_itoa_recursive(num, base, out);
}

/// @brief Converts an integer to a string and appends it to the output string.
/// @param num The integer to convert.
/// @param base The base to use for the conversion.
/// @param out The output string.
/// @warning Check the error flag for memory allocation errors.
void	str_itoa_cat(int num, t_str_slice base, t_str *out)
{
	_str_itoa(num, base, out);
}

/// @brief Converts an integer to a string.
/// @param num The integer to convert.
/// @param base The base to use for the conversion.
/// @return The string representation of the integer.
/// @warning Check the error flag for memory allocation errors.
t_str	str_itoa(int num, t_str_slice base)
{
	t_str	out;

	out = str_empty();
	_str_itoa(num, base, &out);
	return (out);
}
