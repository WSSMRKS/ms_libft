/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:47:48 by kwurster          #+#    #+#             */
/*   Updated: 2024/07/29 13:51:05 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Checks whether the pointer is null.
/// @param ptr The pointer to check.
/// @return Whether the pointer is null.
t_bool	ptr_is_null(const void *ptr)
{
	return (ptr == 0);
}

/// @brief Checks whether the pointer this pointer points to is null.
/// @param ptr The pointer to the pointer.
/// @return Whether the pointer this pointer points to is null.
t_bool	ptr_ptr_is_null(const void *ptr)
{
	return (*(const void **)ptr == 0);
}
