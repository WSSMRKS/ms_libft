/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_clone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:33:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 18:49:07 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_str	str_clone(t_str str)
{
	return (str_new_clone_sized(str_get(&str), str.len));
}

t_str	str_clone_sized(t_str str, size_t new_len)
{
	return (str_new_clone_sized(str_get(&str), new_len));
}
