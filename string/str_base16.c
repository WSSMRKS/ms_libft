/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_base16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:08:24 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#if FT_SMALL_STR >= 17

t_str	str_base16(void)
{
	return ((t_str){.len = 16, .heap = 0, .mem_err = 0,
		._small_string = BASE16});
}

#else

t_str	str_base16(void)
{
	return (str_new_clone_sized(BASE16, 16));
}

#endif
