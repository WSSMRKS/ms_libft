/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfill_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:14:15 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putfill_fd(char c, int32_t fd, size_t fill)
{
	size_t	put_len;

	put_len = 0;
	while (fill--)
		put_len += ft_putchar_fd(c, fd);
	return (put_len);
}
