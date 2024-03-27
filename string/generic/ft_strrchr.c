/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:00:04 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/27 15:09:55 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	return (0);
}

/// returns pointer to first occurence of a char of s from the back which
/// is not c or 0 if no such not matching char exists
char	*ft_strr_notchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if (s[i] != (unsigned char)c)
			return ((char *)s + i);
	return (0);
}
