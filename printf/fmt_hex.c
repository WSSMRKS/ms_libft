/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:40:51 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:23 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	add_padding_hex(t_str *str, t_fmt fmt, t_bool allow_zero,
		unsigned int num)
{
	if (str->len >= fmt.pad.min_width)
		return ;
	if (!allow_zero)
		fmt.pad.fill_char = ' ';
	if (fmt.precision != -1)
		fmt.pad.fill_char = ' ';
	if (fmt.pad.pad_end)
		str_pushn(str, ' ', fmt.pad.min_width - str->len);
	else
	{
		if (fmt.pad.fill_char == '0' && num != 0 && fmt.alternate_form)
			str_get(str)[1] = '0';
		str_pushn_front(str, fmt.pad.fill_char, fmt.pad.min_width - str->len);
		if (fmt.pad.fill_char == '0' && num != 0 && fmt.alternate_form)
			str_get(str)[1] = 'x';
	}
}

t_str	fmt_hex(va_list *args, t_fmt fmt)
{
	t_str			out;
	unsigned int	num;

	num = va_arg(*args, unsigned int);
	out = str_empty();
	sanitize_fmt_unsigned(&fmt);
	ulltoa_base_radix(&out, num, "0123456789abcdef", 16);
	add_precision_leading_zeroes(&out, fmt, FALSE);
	if (num != 0 && fmt.alternate_form)
		str_pushstr_front(&out, "0x");
	add_padding_hex(&out, fmt, TRUE, num);
	return (out);
}
