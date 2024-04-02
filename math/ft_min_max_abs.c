/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max_abs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:57:38 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 10:05:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_ll	ft_max(t_ll a, t_ll b)
{
	if (a > b)
		return (a);
	return (b);
}

t_ll	ft_min(t_ll a, t_ll b)
{
	if (a < b)
		return (a);
	return (b);
}

t_ull	ft_umax(t_ull a, t_ull b)
{
	if (a > b)
		return (a);
	return (b);
}

t_ull	ft_umin(t_ull a, t_ull b)
{
	if (a < b)
		return (a);
	return (b);
}

/// @brief Safely calculate the absolute value of a number.
/// @param num Number to calculate the absolute value of.
/// @param min Minimum value of the number type, e.g. INT_MIN.
/// @return Absolute value of the number.
t_ull	ft_abs(t_ll num, t_ll min)
{
	if (num == min)
		return (((t_ull) - (min + 1)) + 1);
	if (num < 0)
		return (-num);
	return (num);
}
