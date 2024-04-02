/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_filter_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:37:42 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:14:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"

// void	str_filter_map(t_str *str, t_bool (*f)(unsigned char*))
// {
// 	char	*buf;
// 	size_t	index;

// 	buf = str_get(str);
// 	index = 0;
// 	while (index < str->len)
// 	{
// 		if (!f(buf + index))
// 			str_remove(str, index);
// 		else
// 			index++;
// 	}
// }

// void	str_filter_mapi(t_str *str, t_bool (*f)(size_t, unsigned char*))
// {
// 	char	*buf;
// 	size_t	index;

// 	buf = str_get(str);
// 	index = 0;
// 	while (index < str->len)
// 	{
// 		if (!f(index, buf + index))
// 			str_remove(str, index);
// 		else
// 			index++;
// 	}
// }

// void	str_filter_map_rev(t_str *str, t_bool (*f)(unsigned char*))
// {
// 	char	*buf;
// 	size_t	index;

// 	buf = str_get(str);
// 	index = str->len;
// 	while (index--)
// 	{
// 		if (!f(buf + index))
// 			str_remove(str, index);
// 	}
// }

// void	str_filter_mapi_rev(t_str *str, t_bool (*f)(size_t, unsigned char*))
// {
// 	char	*buf;
// 	size_t	index;

// 	buf = str_get(str);
// 	index = str->len;
// 	while (index--)
// 	{
// 		if (!f(index, buf + index))
// 			str_remove(str, index);
// 	}
// }
