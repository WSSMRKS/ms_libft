/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:11:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 23:50:14 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Wraps the given string in a t_str.
/// @param s String to wrap.
/// @param len Length of the given string.
/// @return Wrapped string or empty string if 's' is null.
/// @note Will not malloc.
/// @warning If the given `len` is less than the actual length of the string,
/// the string will NOT be null-terminated.
/// @warning The given string must be freeable (for str_destroy to not crash).
/// @warning The given string may only be used through this wrapper afterwards.
t_str	str_new_from_parts(char *s, size_t len)
{
	if (s)
		return ((t_str){.len = len, ._capacity = len + 1, ._large_string = s,
			.heap = TRUE, .mem_err = FALSE});
	return (str_empty());
}

/// @brief Wraps the given string in a t_str (safely).
/// @note Will malloc if the given 'len' is larger than the len of the string.
/// @param s String to wrap.
/// @param new_len Max length of the resulting string.
/// @return Wrapped string or empty string if 's' is null.
/// @warning The given string must be freeable.
/// @warning The given string may not be used after wrapping.
/// @warning Check the error flag for memory allocation errors.
t_str	str_new_from(char *s, size_t new_len)
{
	t_str	out;
	size_t	actual_len;

	out = str_empty();
	if (s)
	{
		actual_len = ft_strlen(s);
		if (actual_len < new_len)
		{
			out = str_new_clone_sized(s, new_len);
			free(s);
		}
		else
		{
			out.len = ft_umin(actual_len, new_len);
			out._capacity = actual_len + 1;
			s[new_len] = 0;
			out._large_string = s;
			out.heap = TRUE;
		}
	}
	return (out);
}
