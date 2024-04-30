/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 13:15:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_slice.h"

t_str_slice	base16(void)
{
	return (cstr_slice(BASE16, 16));
}

t_str_slice	base16_upper(void)
{
	return (cstr_slice(BASE16_UPPER, 16));
}
