/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_from.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:11:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:46 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Wraps the given string in a t_str.
/// @note Will not malloc.
/// @param s String to wrap.
/// @param len Length of the given string or less.
/// @return Wrapped string or empty string if 's' is null.
/// @warning May access invalid memory if the given 'len' is out of bounds.
/// @warning The given string must be freeable.
/// @warning The given string may not be used after wrapping.
t_str	str_new_from(char *s, size_t len)
{
	t_str	str;

	str = str_empty();
	if (s)
	{
		str.len = len;
		str._capacity = len + 1;
		str._large_string = s;
		str._large_string[len] = 0;
		str.heap = TRUE;
	}
	return (str);
}

/// @brief Wraps the given string in a t_str.
/// @note Will malloc if the given 'len' is larger than the len of the string.
/// @param s String to wrap.
/// @param new_len Max length of the resulting string.
/// @return Wrapped string or empty string if 's' is null.
/// @warning The given string must be freeable.
/// @warning The given string may not be used after wrapping.
/// @warning Check the error flag for memory errors.
t_str	str_new_from_sized(char *s, size_t new_len)
{
	t_str	str;
	size_t	actual_len;

	str = str_empty();
	if (s)
	{
		actual_len = ft_strlen(s);
		if (actual_len < new_len)
		{
			str = str_new_clone_sized(s, new_len);
			free(s);
		}
		else
		{
			str.len = new_len;
			str._capacity = actual_len + 1;
			s[new_len] = 0;
			str._large_string = s;
			str.heap = TRUE;
		}
	}
	return (str);
}
