/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:44 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 16:46:59 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*_itoa(unsigned int n, int depth)
{
	char	*out;

	if (n == 0)
	{
		out = malloc(depth + 1);
		if (!out)
			return (0);
		out[depth] = '\0';
		return (out);
	}
	out = _itoa(n / 10, depth + 1);
	if (!out)
		return (0);
	out[depth] = '0' + (n % 10);
	return (out);
}

static char	*zero()
{
	char	*out;

	out = malloc(2);
	if (!out)
		return (0);
	out[0] = '0';
	out[1] = '\0';
	return (out);
}

char	*ft_itoa(int n)
{
	char	*out;

	if (n > 0)
		return _itoa(n, 0);
	else if (n == 0)
		return (zero());
	else
	{
		out = _itoa(-(n / 10), 2);
		if (!out)
			return (0);
		out[0] = '-';
		out[1] = '0' + (-(n % 10));
		return (out);
	}
	return (out);
}
