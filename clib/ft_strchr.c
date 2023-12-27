/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:51:54 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/25 23:39:15 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
