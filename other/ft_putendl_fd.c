/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:36:55 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "unistd.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	return (ft_putstr_fd(s, fd) + write(fd, "\n", 1));
}
