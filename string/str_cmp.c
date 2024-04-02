/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:56:42 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:05:24 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Checks if the given string is identical to another string.
/// Strings can be equal but not be identical
/// if the data location is different.
/// @param str1
/// @param str2
/// @return TRUE if the strings are identical, FALSE otherwise.
t_bool	str_identical(t_str str1, t_str str2)
{
	if (str1.heap)
		return (str2.heap && str1._large_string == str2._large_string);
	return (ft_strcmp(str1._small_string, str2._small_string) == 0);
}

int	str_cmp(t_str str1, t_str str2)
{
	return (ft_strcmp(str_get(&str1), str_get(&str2)));
}
