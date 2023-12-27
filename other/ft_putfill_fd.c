/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfill_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:14:15 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 17:20:28 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putfill_fd(char c, int fd, size_t fill)
{
	size_t	put_len;

	put_len = 0;
	while (fill--)
		put_len += ft_putchar_fd(c, fd);
	return (put_len);
}
