/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:37:04 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/06 19:38:44 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	fmt_str(va_list *args, t_fmt fmt)
{
	t_str	out;
	size_t	out_len;
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		if (fmt.precision < 0 || fmt.precision >= 6)
			out = str_new_clone_sized("(null)", 6);
		else
			out = str_empty();
	}
	else
	{
		out_len = ft_strlen(s);
		if (fmt.precision >= 0 && (size_t)fmt.precision < out_len)
			out_len = fmt.precision;
		out = str_new_clone_sized(s, out_len);
	}
	add_padding(&out, fmt, FALSE);
	return (out);
}