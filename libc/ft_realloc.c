/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:14:23 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/27 15:08:42 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>
#include <stdlib.h>

/// @brief Reallocates a memory block.
/// @param ptr Pointer to the memory block to reallocate.
/// @param from Size of the memory block to reallocate.
/// @param to New size of the memory block.
/// @return Pointer to the reallocated memory block.
void	*ft_realloc(void *ptr, size_t from, size_t to)
{
	void	*new_ptr;

	new_ptr = malloc(to);
	if (!new_ptr)
		return (0);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, ft_umin(from, to));
		free(ptr);
	}
	return (new_ptr);
}

/// @brief Reallocates a memory block.
/// @param ptr Pointer to the memory block to reallocate.
/// @param from Size of the memory block to reallocate.
/// @param nmemb Number of elements.
/// @param size Size of each element.
/// @return Pointer to the reallocated memory block.
void	*ft_reallocarray(void *ptr, size_t from, size_t nmemb, size_t size)
{
	t_ull new_size;
	if (ft_safe_umult(nmemb, size, ULLONG_MAX, &new_size))
		return (0);
	return (ft_realloc(ptr, from, (size_t) new_size));
}

/// @brief Reallocates a string.
/// @param ptr Pointer to the string to reallocate.
/// @param to New size of the string.
/// @return Pointer to the reallocated string.
char	*ft_reallocstring(char *ptr, size_t to)
{
	char	*new_ptr;

	new_ptr = malloc(to);
	if (!new_ptr)
		return (0);
	new_ptr[0] = 0;
	if (ptr)
	{
		ft_strlcpy(new_ptr, ptr, to);
		free(ptr);
	}
	return (new_ptr);
}
