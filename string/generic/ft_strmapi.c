/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:28 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 06:00:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

unsigned char	*ft_strmapi(const unsigned char *s, unsigned char (*f)(unsigned int, unsigned char))
{
	unsigned char	*out;
	unsigned int	i;

	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (0);
	i = 0;
	while (*s)
	{
		out[i] = f(i, *s++);
		i++;
	}
	out[i] = '\0';
	return (out);
}
