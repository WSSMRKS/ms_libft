/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:38:35 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:20 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putnbr_fd(int32_t n, int32_t fd)
{
	long	n_long;
	size_t	out_width;

	n_long = n;
	out_width = 0;
	if (n_long < 0)
	{
		out_width += ft_putchar_fd('-', fd);
		n_long *= -1;
	}
	if (n_long >= 10)
		out_width += ft_putnbr_fd(n_long / 10, fd);
	return (out_width + ft_putchar_fd('0' + (n_long % 10), fd));
}
