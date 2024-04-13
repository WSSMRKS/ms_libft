/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:30:05 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:25 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft.h"
# include <stdarg.h>

typedef enum e_flag_kind
{
	FLAG_PAD_END = '-',
	FLAG_SIGN_PLUS = '+',
	FLAG_SIGN_SPACE = ' ',
	FLAG_ALT = '#',
	FLAG_PAD_ZERO = '0',
}				t_flag_kind;

typedef struct s_padding
{
	char		fill_char;
	size_t		min_width;
	t_bool		pad_end;
}				t_padding;

typedef struct s_spec
{
	const char	*spec_str;
	int			fmt_fn_index;
}				t_spec;

typedef struct s_fmt
{
	t_bool		bad_fmt;
	t_bool		malloc_err;
	t_spec		specifier;
	t_bool		alternate_form;
	char		*pos_nbr_sign;
	t_padding	pad;
	int			precision;
}				t_fmt;

typedef t_str	(*t_fmt_fn)(va_list *, t_fmt);

int				ft_printf(const char *s, ...);

t_str			fmt_c(va_list *args, t_fmt fmt);
t_str			fmt_str(va_list *args, t_fmt fmt);
t_str			fmt_ptr(va_list *args, t_fmt fmt);
t_str			fmt_int(va_list *args, t_fmt fmt);
t_str			fmt_uint(va_list *args, t_fmt fmt);
t_str			fmt_hex(va_list *args, t_fmt fmt);
t_str			fmt_hexup(va_list *args, t_fmt fmt);
t_str			percent_char(va_list *args, t_fmt fmt);

void			init_fmt(t_fmt *fmt);
void			parse_formatting(const char *s, t_fmt *fmt);
void			add_padding(t_str *str, t_fmt fmt, t_bool allow_zero);

void			add_precision_leading_zeroes(t_str *str, t_fmt fmt,
					t_bool has_sign);
void			swap_sign_with_leading_zero(t_str *str, t_fmt fmt,
					t_bool is_neg);
void			ulltoa_base_radix(t_str *out, unsigned long long num,
					const char *base, size_t radix);
void			sanitize_fmt_unsigned(t_fmt *fmt);

#endif
