/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:47:22 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/// @brief Creates an empty string.
/// @note Will not malloc.
/// @return Empty string.
t_str	str_empty(void)
{
	t_str	str;

	str.len = 0;
	str.heap = FALSE;
	str.mem_err = FALSE;
	str._small_string[0] = 0;
	return (str);
}

/// @brief Creates an empty string with the given capacity.
/// @param n Capacity of the string.
/// @return Empty string.
/// @warning May return with a lower capacity if memory allocation fails.
/// @warning Check the error flag for memory errors.
t_str	str_empty_with_capacity(size_t n)
{
	t_str	str;

	str = str_empty();
	str_set_capacity(&str, n);
	return (str);
}
