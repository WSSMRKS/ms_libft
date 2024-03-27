/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:51:54 by kwurster          #+#    #+#             */
/*   Updated: 2024/01/01 19:37:21 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)s - 1);
	if (c == 0)
		return ((char *)s);
	return (0);
}

/// returns pointer to first occurence of a char in s which is not c
/// or 0 if no such not matching char exists
char	*ft_str_notchr(const char *s, int c)
{
	while (*s)
		if (*s++ != (unsigned char)c)
			return ((char *)s - 1);
	if (c != 0)
		return ((char *)s);
	return (0);
}
