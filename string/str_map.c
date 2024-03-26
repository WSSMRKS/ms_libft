/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:32:17 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:37:27 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_map(t_str *str, void (*f)(char*))
{
	char	*buf;
	size_t	index;

	buf = str_get(str);
	index = 0;
	while (index < str->len)
		f(buf + index++);
}

void	str_mapi(t_str *str, void (*f)(size_t, char*))
{
	char	*buf;
	size_t	index;

	buf = str_get(str);
	index = 0;
	while (index < str->len)
	{
		f(index, buf + index);
		index++;
	}

}

void	str_map_rev(t_str *str, void (*f)(char*))
{
	char	*buf;
	size_t	index;

	buf = str_get(str);
	index = str->len;
	while (index--)
		f(buf + index);
}

void	str_mapi_rev(t_str *str, void (*f)(size_t, char*))
{
	char	*buf;
	size_t	index;

	buf = str_get(str);
	index = str->len;
	while (index--)
		f(index, buf + index);
}
