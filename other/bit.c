/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:51:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/27 19:54:13 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	set_bit(unsigned char *byte, unsigned char pos)
{
	*byte |= 1 << pos;
}

void	unset_bit(unsigned char *byte, unsigned char pos)
{
	*byte &= ~(1 << pos);
}

void	toggle_bit(unsigned char *byte, unsigned char pos)
{
	*byte ^= 1 << pos;
}

void	set_bit_as(unsigned char *byte, unsigned char pos, t_ull bool)
{
	if (bool != 0) {
		set_bit(byte, pos);
	} else {
		unset_bit(byte, pos);
	}
}

t_bool	get_bit(unsigned char byte, unsigned char pos)
{
	return ((byte >> pos) & 1);
}
