/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:06:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:47 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_;
	char		*dest_;

	src_ = src;
	dest_ = dest;
	if (src < dest)
		while (n-- > 0)
			dest_[n] = src_[n];
	else if (src > dest)
		while (dest_ <= &((char *)dest)[n - 1])
			*dest_++ = *src_++;
	return (dest);
}
