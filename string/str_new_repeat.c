/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_repeat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:44:07 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/27 20:50:14 by kwurster         ###   ########.fr       */
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
	str_new_repeat_sized(s, len, len * n, n);
}

/// @brief Creates a string by repeating the given string 'n' times.
/// @param s String to repeat.
/// @param l Length of the given string or less.
/// @param new_len Max length of the resulting string.
/// @param n Number of repetitions.
/// @return Repeated string or empty string if 's' is null.
/// @warning Check the error flag for memory allocation errors.
t_str	str_new_repeat_sized(const char *s, size_t l, size_t new_len, size_t n)
{
	t_str	str;
	size_t	cap;
	size_t	offset;
	size_t	src_len;
	char	*buf;

	str = str_empty_with_capacity(new_len + 1);
	cap = str_capacity(str);
	if (s && cap > new_len)
	{
		buf = str_get(&str);
		offset = 0;
		while (cap > offset && n--)
		{
			src_len = ft_strlcpy(buf + offset, s, ft_min(cap - offset, l + 1));
			offset += ft_min(src_len, ft_min(new_len - offset, l));
		}
		str.len = offset;
	}
	return (str);
}
