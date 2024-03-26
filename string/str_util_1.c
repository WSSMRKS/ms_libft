/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:33:56 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/25 23:31:35 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_bool	str_is_on_heap(t_str str)
{
	return (str.capacity > LIBFT_SMALL_STRING_SIZE);
}

t_str	str_clone(t_str str)
{
	return (str_new_cloned(str_get(&str), str.len));
}

t_bool	str_is_empty(t_str str)
{
	return (str.len == 0);
}

void	str_destroy(t_str *str)
{
	if (str_is_on_heap(*str))
		free(str->large_string);
	str->len = 0;
	str->capacity = LIBFT_SMALL_STRING_SIZE;
	str->small_string[0] = 0;
	str->err = FALSE;
}

void	str_clear(t_str *str)
{
	str_get(str)[0] = 0;
	str->len = 0;
	str->err = FALSE;
}
