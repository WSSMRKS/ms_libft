/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:53:49 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 06:00:29 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

unsigned char	*ft_strnstr(const unsigned char *big, const unsigned char *little, size_t len)
{
	size_t	little_len;

	if (!*little)
		return ((unsigned char *)big);
	little_len = ft_strlen(little);
	while (len >= little_len && *big)
	{
		if (!ft_strncmp(big, little, little_len))
			return ((unsigned char *)big);
		big++;
		len--;
	}
	return (0);
}
