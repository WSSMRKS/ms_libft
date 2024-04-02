/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:17:28 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:10:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlen(const unsigned char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
