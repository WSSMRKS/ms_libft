/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_base8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:08:42 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#if FT_SMALL_STR >= 9

t_str	str_base8(void)
{
	return ((t_str){.len = 8, .heap = 0, .mem_err = 0, ._small_string = BASE8});
}

#else

t_str	str_base8(void)
{
	return (str_new_clone_sized(BASE8, 8));
}

#endif
