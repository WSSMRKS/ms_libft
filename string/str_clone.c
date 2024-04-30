/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:33:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 17:04:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/// @brief Clone a string.
/// @param str The string to clone.
/// @return The cloned string.
/// @warning Check the error flag for memory allocation errors.
t_str	str_clone(const t_str *str)
{
	return (str_clone_from(str_view(str)));
}
