/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_repeat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:44:07 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 18:44:05 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Creates a string by repeating the given string 'n' times.
/// @param s String to repeat.
/// @param len Length of the given string or less.
/// @param n Number of repetitions.
/// @return Repeated string or empty string if 's' is null.
/// @warning Check the error flag for memory allocation errors.
t_str	str_new_repeat(const char *s, size_t len, size_t n)
{
	return (str_new_repeat_sized(s, len, len * n, n));
}

/// @brief Creates a string by repeating the given string 'n' times.
/// @param str String to repeat.
/// @param str_len Length of the given string or less.
/// @param new_len Max length of the resulting string.
/// @param n Number of repetitions.
/// @return Repeated string or empty string if 'str' is null.
/// @warning Check the error flag for memory allocation errors.
t_str	str_new_repeat_sized(const char *str, size_t str_len, size_t new_len, size_t n)
{
	t_str	out;
	size_t	cap;
	size_t	offset;
	size_t	src_len;
	char	*buf;

	out = str_empty_with_capacity(new_len + 1);
	cap = str_capacity(out);
	if (str && cap > new_len)
	{
		buf = str_get(&out);
		offset = 0;
		while (cap > offset && n--)
		{
			src_len = ft_strlcpy(buf + offset, str, ft_umin(cap - offset, str_len + 1));
			offset += ft_umin(src_len, ft_umin(new_len - offset, str_len));
		}
		out.len = offset;
	}
	return (out);
}
