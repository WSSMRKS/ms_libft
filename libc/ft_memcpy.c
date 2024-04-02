/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:54:36 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_;
	unsigned char		*dest_;

	src_ = src;
	dest_ = dest;
	if (!dest || !src)
		return (0);
	while (n > 0)
	{
		n--;
		dest_[n] = src_[n];
	}
	return (dest);
}
