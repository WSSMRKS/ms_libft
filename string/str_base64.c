/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_base64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:40:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 17:08:26 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#if FT_SMALL_STR >= 65

t_str	str_base64(void)
{
	return ((t_str){.len = 64, .heap = 0, .mem_err = 0, ._small_string = BA64});
}

#else

t_str	str_base64(void)
{
	return (str_new_clone_sized(BA64, 64));
}

#endif
