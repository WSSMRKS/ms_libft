/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:45:21 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:59:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

unsigned char	*ft_strdup(const unsigned char *s)
{
	size_t			len;
	unsigned char	*out;

	len = ft_strlen(s) + 1;
	out = malloc(len);
	if (out)
		ft_memcpy(out, s, len);
	return (out);
}

unsigned char	*ft_strndup(const unsigned char *s, size_t len)
{
	unsigned char	*out;

	out = malloc(len + 1);
	if (out)
		ft_memcpy(out, s, len + 1);
	return (out);
}
