/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:56:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:32:10 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	str_pop(t_str *str)
{
	char	*buf;
	char	out;

	if (str->len == 0)
		return (0);
	buf = str_get(str);
	out = buf[--(str->len)];
	buf[str->len] = 0;
	return (out);
}

char	str_remove(t_str *str, size_t index)
{
	char	*buf;
	char	out;

	if (index >= str->len)
		return (0);
	buf = str_get(str);
	out = buf[index];
	while (index + 1 < str->len)
	{
		buf[index] = buf[index + 1];
		index++;
	}
	buf[index] = 0;
	str->len--;
	return (out);
}

void	str_remove_range(t_str *str, size_t start, size_t end)
{
	char	*buf;
	size_t	skip_len;
	size_t	index;

	skip_len = ft_min(end, str->len) - start;
	buf = str_get(str);
	index = start;
	while (index + skip_len < str->len)
	{
		buf[index] = buf[index + skip_len];
		index++;
	}
	buf[index] = 0;
	str->len -= skip_len;
}

void	str_trunc(t_str *str, size_t len)
{
	str_remove_range(str, str->len - len, str->len);
}
