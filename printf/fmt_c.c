/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:56:01 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 14:13:54 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	fmt_c(va_list *args, t_fmt fmt)
{
	t_str	out;

	out = str_empty();
	str_push(&out, va_arg(*args, int32_t));
	add_padding(&out, fmt, FALSE);
	return (out);
}
