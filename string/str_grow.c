/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:27:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:46 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_bool	str_grow(t_str *str, size_t min_growth)
{
	size_t	new_capacity;

	new_capacity = (str_capacity(*str) + min_growth) * FT_STR_GROW;
	return (str_set_capacity(str, new_capacity));
}

t_bool	str_shrink_to_fit(t_str *str)
{
	size_t	fit_size;

	fit_size = str->len + 1;
	if (str_capacity(*str) != fit_size)
		return (str_set_capacity(str, fit_size));
	return (TRUE);
}
