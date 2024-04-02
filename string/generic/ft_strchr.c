/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:51:54 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:59:21 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	*ft_strchr(const unsigned char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((unsigned char *)s - 1);
	if (c == 0)
		return ((unsigned char *)s);
	return (0);
}

/// returns pointer to first occurence of a char in s which is not c
/// or 0 if no such not matching char exists
unsigned char	*ft_str_notchr(const unsigned char *s, int c)
{
	while (*s)
		if (*s++ != (unsigned char)c)
			return ((unsigned char *)s - 1);
	if (c != 0)
		return ((unsigned char *)s);
	return (0);
}
