/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:44 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 20:22:11 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		len;
	long	n_long;

	len = numlen(n);
	out = malloc(len + 1);
	if (!out)
		return (0);
	out[len] = '\0';
	out[0] = '0';
	n_long = n;
	if (n_long < 0)
	{
		out[0] = '-';
		n_long *= -1;
	}
	while (n_long)
	{
		out[--len] = '0' + (n_long % 10);
		n_long /= 10;
	}
	return (out);
}
