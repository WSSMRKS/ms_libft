/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:11:36 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:07:27 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Gives read access to the string data.
/// @param str String to read from.
/// @return Pointer to the string data.
char	*str_get(t_str *str)
{
	if (str->capacity > LIBFT_SMALL_STRING_SIZE)
		return (str->large_string);
	return (&str->small_string);
}
/// @brief Destroys the given string and returns its data.
/// @param str String to destroy.
/// @return Pointer to the string data or null.
char	*str_take(t_str* str)
{
	char	*out;
	if (str->capacity > LIBFT_SMALL_STRING_SIZE)
	{
		out = str->large_string;
	} else {
		out = ft_strndup(&str->small_string, str->len);
	}
	*str = str_empty();
	return (out);
}

/// @brief Clones the data of the given string.
/// @param str String to clone.
/// @return Pointer to the cloned string data or null.
char	*str_get_cloned(t_str str)
{
	char	*buf;
	if (str.capacity > LIBFT_SMALL_STRING_SIZE)
		buf = str.large_string;
	else
		buf = &str.small_string;
	return (ft_strndup(buf, str.len));
}
