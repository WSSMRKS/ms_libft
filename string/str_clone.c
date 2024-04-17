/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:33:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 22:21:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Clone a string.
/// @param str The string to clone.
/// @return The cloned string.
/// @warning Check the error flag for memory allocation errors.
t_str	str_clone(t_str str)
{
	return (str_new_clone_sized(str_get(&str), str.len));
}

/// @brief Clone a string with a given max size.
/// @param str The string to clone.
/// @param new_len The max size of the cloned string.
/// @return The cloned string.
/// @warning Check the error flag for memory allocation errors.
t_str	str_clone_sized(t_str str, size_t new_len)
{
	return (str_new_clone_sized(str_get(&str), new_len));
}
