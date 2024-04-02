/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:12:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:58:44 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

unsigned char	**ft_split_recursion(const unsigned char *s, unsigned char c, int i, size_t len)
{
	unsigned char	**out;
	unsigned char	*str;

	if (!s)
		return (malloc((i + 1) * sizeof(unsigned char *)));
	while (s[len] && s[len] != c)
		len++;
	str = ft_substr(s, 0, len);
	if (str == 0)
		return (0);
	s = s + len;
	while (*s && *s == c)
		s++;
	if (!*s)
		s = 0;
	out = ft_split_recursion(s, c, i + 1, 0);
	if (!out)
	{
		free(str);
		return (0);
	}
	if (!s)
		out[i + 1] = 0;
	out[i] = str;
	return (out);
}

unsigned char	**ft_split(const unsigned char *s, unsigned char c)
{
	unsigned char	**out;

	while (*s && *s == c)
		s++;
	if (*s)
		return (ft_split_recursion(s, c, 0, 0));
	out = malloc(sizeof(unsigned char *));
	if (out)
		*out = 0;
	return (out);
}
