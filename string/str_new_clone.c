/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new_clone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:13:04 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/27 20:36:21 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Clones the given string.
/// @param s String to clone.
/// @param new_len Max length of the resulting string.
/// @return Cloned string or empty string if 's' is null.
/// @warning Check the error flag for memory allocation errors.
t_str	str_new_clone_sized(const char *s, size_t new_len)
{
	t_str	str;
	size_t	cap;

	str = str_empty_with_capacity(new_len + 1);
	cap = str_capacity(str);
	if (s && cap > new_len) {
		str.len = ft_min(ft_strlcpy(str_get(&str), s, cap), new_len);
	}
	return (str);
}
