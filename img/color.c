/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:21:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/07/30 21:27:12 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_img.h"

t_bool	is_transparent(uint32_t color)
{
	return (color >> 24 == TRANSPARENT);
}

t_bool	is_opaque(uint32_t color)
{
	return (color >> 24 != TRANSPARENT);
}

uint32_t	blend_colors(uint32_t bg, uint32_t color)
{
	uint8_t		alpha;
	uint32_t	mask;

	alpha = color >> 24;
	mask = ~((alpha == TRANSPARENT) - 1);
	return ((bg & mask) | (color & ~mask));
}
