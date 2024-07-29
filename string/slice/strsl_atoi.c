/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsl_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:44:55 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/28 02:22:27 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_slice.h"

static int	handle_sign(t_str_slice *s)
{
	int	sign;

	if (!s->len)
		return (0);
	sign = 1;
	if (*s->str == '-')
	{
		sign = -1;
		strsl_move_inplace(s, 1);
	}
	else if (*s->str == '+')
		strsl_move_inplace(s, 1);
	return (sign);
}

/// @brief Handle the next digit in the string.
/// @param out The current value of the integer to be modified.
/// @param c The current char.
/// @param sign The sign of the integer.
/// @param base The base to use for the conversion.
/// @return 1 if the conversion was successful, 0 if the char is invalid, 2 if
/// the integer overflowed and was capped at INT_MIN or INT32_MAX.
static int	handle_next_char(int *out, char c, int sign, t_str_slice base)
{
	const char	*base_match;
	int			digit;

	base_match = strsl_chr(base, c);
	if (!c || !base_match)
		return (FALSE);
	digit = (int)(base_match - base.str);
	if (*out > INT32_MAX / 10 || (*out == INT32_MAX / (int)base.len
			&& digit > INT32_MAX % (int)base.len))
	{
		if (sign == -1)
			*out = INT32_MIN;
		else
			*out = INT32_MAX;
		return (2);
	}
	*out *= base.len;
	*out += digit;
	return (TRUE);
}

static void	skip_whitespace(t_str_slice *s)
{
	while (s->len && ft_isspace(*s->str))
		strsl_move_inplace(s, 1);
}

static void	skip_base(t_str_slice *s, t_str_slice base)
{
	while (s->len && strsl_chr(base, *s->str))
		strsl_move_inplace(s, 1);
}

/// @brief Convert a string to an integer.
/// @param s The string to convert.
/// @param base The base to use for the conversion.
/// @param out The integer to write to.
/// @param ofb The overflow behavior.
/// @return True if the conversion was successful, FALSE otherwise.
/// @note Will skip leading/trailing whitespace and accept an optional sign.
/// @note Will return FALSE if the string is empty or contains invalid chars.
t_bool	strsl_atoi(t_str_slice s, t_str_slice base, int *out,
		t_overflow_behavior ofb)
{
	int		sign;
	t_bool	ok;
	int		code;

	skip_whitespace(&s);
	sign = handle_sign(&s);
	*out = 0;
	ok = FALSE;
	code = 1;
	if (s.len && ft_isdigit(*s.str))
		ok = TRUE;
	while (s.len && code == 1)
		code = handle_next_char(out, *strsl_ref_move(&s, 1), sign, base);
	if (*out != INT32_MAX && *out != INT32_MIN)
		*out *= sign;
	skip_base(&s, base);
	skip_whitespace(&s);
	if (s.len)
		return (FALSE);
	return (ok && (ofb == OFB_TRUNCATE || !(ofb == OFB_ERROR && code == 2)));
}
