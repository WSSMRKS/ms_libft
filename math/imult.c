/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imult.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:30:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/07/29 12:18:38 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_bool	i8mult(int8_t var1, int8_t var2, int8_t *out)
{
	*out = var1 * var2;
	if (var1 == 0 || var2 == 0)
		return (TRUE);
	return (var1 == *out / var2);
}

t_bool	i16mult(int16_t var1, int16_t var2, int16_t *out)
{
	*out = var1 * var2;
	if (var1 == 0 || var2 == 0)
		return (TRUE);
	return (var1 == *out / var2);
}

t_bool	i32mult(int32_t var1, int32_t var2, int32_t *out)
{
	*out = var1 * var2;
	if (var1 == 0 || var2 == 0)
		return (TRUE);
	return (var1 == *out / var2);
}

t_bool	i64mult(int64_t var1, int64_t var2, int64_t *out)
{
	*out = var1 * var2;
	if (var1 == 0 || var2 == 0)
		return (TRUE);
	return (var1 == *out / var2);
}

t_bool	isizemult(ssize_t var1, ssize_t var2, ssize_t *out)
{
	*out = var1 * var2;
	if (var1 == 0 || var2 == 0)
		return (TRUE);
	return (var1 == *out / var2);
}
