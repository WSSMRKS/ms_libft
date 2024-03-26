/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:27:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:13:43 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	str_grow(t_str *str, size_t min_growth)
{
	size_t	new_capacity;

	new_capacity = (str->capacity + min_growth) * ft_umax(1, LIBFT_STRING_GROW_FACTOR);
	return (str_set_capacity(str, new_capacity));
}

t_bool	str_shrink_to_fit(t_str *str)
{
	size_t	fit_size;

	fit_size = str->len + 1;
	if (str->capacity != fit_size) {
		return (str_set_capacity(str, fit_size));
	}
	return (TRUE);
}
