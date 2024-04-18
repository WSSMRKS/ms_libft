/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_base10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:08:22 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#if FT_SMALL_STR >= 11

t_str	str_base10(void)
{
	return ((t_str){.len = 10, .heap = 0, .mem_err = 0,
		._small_string = BASE10});
}

#else

t_str	str_base10(void)
{
	return (str_new_clone_sized(BASE10, 10));
}

#endif
