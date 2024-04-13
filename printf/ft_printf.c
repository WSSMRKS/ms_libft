/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:29:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:05:19 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	fmt_fn_index(const char *s)
{
	const char			*fn_pos;
	static const char	specifiers[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X',
		'%'};

	fn_pos = ft_memchr(specifiers, *s, sizeof(specifiers));
	if (fn_pos == 0)
		return (-1);
	return (fn_pos - specifiers);
}

/// Goes through the string and returns the specifier
static t_spec	find_specifier(const char *s)
{
	t_spec	specifier;

	specifier.fmt_fn_index = -1;
	while (*s)
	{
		specifier.fmt_fn_index = fmt_fn_index(s);
		if (specifier.fmt_fn_index != -1)
			break ;
		s++;
	}
	specifier.spec_str = s;
	return (specifier);
}

int	print_formatted_arg(const char **fmt_begin, va_list *arg)
{
	t_fmt					fmt;
	t_str					formatted_arg;
	int						put_width;
	static const t_fmt_fn	fmt_functions[9] = {fmt_c, fmt_str, fmt_ptr,
		fmt_int, fmt_int, fmt_uint, fmt_hex, fmt_hexup, percent_char};

	init_fmt(&fmt);
	(*fmt_begin)++;
	fmt.specifier = find_specifier(*fmt_begin);
	if (fmt.specifier.fmt_fn_index == -1 || *fmt.specifier.spec_str == 0)
		return (-1);
	parse_formatting(*fmt_begin, &fmt);
	formatted_arg = fmt_functions[fmt.specifier.fmt_fn_index](arg, fmt);
	if (formatted_arg.mem_err)
	{
		str_destroy(&formatted_arg);
		return (-1);
	}
	*fmt_begin = fmt.specifier.spec_str + 1;
	put_width = write(1, str_get(&formatted_arg), formatted_arg.len);
	str_destroy(&formatted_arg);
	return (put_width);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		total_put_width;
	int		put_width;

	va_start(args, s);
	total_put_width = 0;
	while (s && *s)
	{
		if (*s != '%')
		{
			if (write(1, s, 1) != 1)
				break ;
			total_put_width++;
			s++;
			continue ;
		}
		put_width = print_formatted_arg((const char **)&s, &args);
		if (put_width == -1)
			break ;
		total_put_width += put_width;
	}
	va_end(args);
	if (!s || *s || put_width == -1)
		return (-1);
	return (total_put_width);
}
