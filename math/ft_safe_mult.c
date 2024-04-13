/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:30:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:16 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Safely multiplies two signed integers.
/// @param a First factor.
/// @param b Second factor.
/// @param max Maximum for the integer type, e.g. INT_MAX for int.
/// @param result Pointer to the result.
/// @return TRUE if the multiplication is safe, FALSE if it overflows.
t_bool	ft_safe_mult(long long a, long long b, long long max, long long *result)
{
	long long	min;

	min = -max - 1;
	*result = 0;
	if (a == 0 || b == 0)
		return (TRUE);
	if (a > 0 && b > 0 && a > max / b)
		return (FALSE);
	if (a < 0 && b > 0 && a < min / b)
		return (FALSE);
	if (a > 0 && b < 0 && b < min / a)
		return (FALSE);
	if (a < 0 && b < 0 && a < max / b)
		return (FALSE);
	*result = a * b;
	return (TRUE);
}

/// @brief Safely multiplies two unsigned integers.
/// @param a First factor.
/// @param b Second factor.
/// @param max Maximum for the integer type, e.g. UINT_MAX for unsigned int.
/// @param result Pointer to the result.
/// @return TRUE if the multiplication is safe, FALSE if it overflows.
t_bool	ft_safe_umult(unsigned long long a, unsigned long long b,
		unsigned long long max, unsigned long long *result)
{
	*result = 0;
	if (a == 0 || b == 0)
		return (TRUE);
	if (a > max / b)
		return (FALSE);
	*result = a * b;
	return (TRUE);
}
