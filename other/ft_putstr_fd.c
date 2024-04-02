/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:34:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:14:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_putstr_fd(unsigned char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (write(fd, s, len));
}
