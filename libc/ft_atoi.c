/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:00:27 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:04:37 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\t' || c == '\f');
}

static int	get_and_skip_sign(const char **nptr)
{
	if (**nptr == '-')
	{
		(*nptr)++;
		return (-1);
	}
	if (**nptr == '+')
		(*nptr)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nbr;

	while (ft_isspace(*nptr))
		nptr++;
	sign = get_and_skip_sign(&nptr);
	nbr = 0;
	while (ft_isdigit(*nptr))
	{
		if (nbr > INT_MAX / 10 || (nbr == INT_MAX / 10 && *nptr > '7'))
		{
			if (sign == -1)
				return (INT_MIN);
			return (INT_MAX);
		}
		nbr = (nbr * 10) + *nptr - '0';
		nptr++;
	}
	return (sign * nbr);
}
