/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:30:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/25 18:54:38 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Safely multiplies two signed integers.
/// @param a First factor.
/// @param b Second factor.
/// @param max Maximum for the integer type, e.g. INT_MAX for int.
/// @param result Pointer to the result.
/// @return TRUE if the multiplication is safe, FALSE if it overflows.
t_bool	ft_safe_mult(t_ll a, t_ll b, t_ll max, t_ll *result)
{
	t_ll	min;

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
t_bool	ft_safe_umult(t_ull a, t_ull b, t_ull max, t_ull *result)
{
	*result = 0;
	if (a == 0 || b == 0)
		return (TRUE);
	if (a > max / b)
		return (FALSE);
	*result = a * b;
	return (TRUE);
}
