/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:47:22 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:07:27 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

t_str	str_empty()
{
	return (str_empty_with_capacity(LIBFT_SMALL_STRING_SIZE));
}

t_str	str_empty_with_capacity(size_t n)
{
	t_str	str;

	str.len = 0;
	str.capacity = ft_umax(n, LIBFT_SMALL_STRING_SIZE);
	if (str_is_on_heap(str))
	{
		str.large_string = malloc(n);
		if (str.large_string)
			str.large_string[0] = 0;
		str.err = str.large_string == 0;
	} else {
		str.small_string[0] = 0;
		str.err = FALSE;
	}
	return (str);
}

t_str	str_new_from(char *s, size_t len)
{
	t_str	str;

	str.len = len;
	str.capacity = str.len + 1;
	str.large_string = s;
	str.err = FALSE;
	return (str);
}

t_str	str_new_cloned(const char *s, size_t len)
{
	t_str	str;

	str = str_empty_with_capacity(len + 1);
	if (str.err)
		return (str);
	ft_memcpy(str_get(&str), s, str.capacity);
	str.len = len;
	return (str);
}

t_str	str_new_repeat(const char *s, size_t len, size_t n)
{
	t_str	str;
	char	*buf;

	str = str_empty_with_capacity(len * n + 1);
	if (str.err)
		return (str);
	buf = str_get(&str);
	while (n--)
	{
		ft_memcpy(buf + str.len, s, len);
		str.len += len;
	}
	buf[str.len] = 0;
	return (str);
}
