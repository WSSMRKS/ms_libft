/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:23:43 by kwurster          #+#    #+#             */
/*   Updated: 2024/09/10 14:43:15 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_geo.h"

t_bool	rect_contains(t_rect rect, t_point point)
{
	return (
		point.x >= rect.from.x && point.x < rect.to.x
		&& point.y >= rect.from.y && point.y < rect.to.y
	);
}
