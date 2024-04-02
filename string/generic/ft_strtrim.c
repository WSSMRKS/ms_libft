/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:47:40 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 06:01:20 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft.h"

static int	set_contains(const unsigned char *set, unsigned char c)
{
	while (*set)
		if (*set++ == (unsigned char)c)
			return (1);
	return (0);
}

/**
 * Removes leading and trailing characters from a string
 * based on a given set of characters.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be removed.
 * @return A newly allocated trimmed string, or NULL if memory allocation fails.
 */
unsigned char	*ft_strtrim(const unsigned char *s1, const unsigned char *set)
{
	size_t			len;
	unsigned char	*out;

	while (set_contains(set, *s1))
		s1++;
	len = 0;
	while (s1[len])
		len++;
	while (len && set_contains(set, s1[len - 1]))
		len--;
	out = malloc(len + 1);
	if (!out)
		return (0);
	out[len] = 0;
	ft_memcpy(out, s1, len);
	return (out);
}
