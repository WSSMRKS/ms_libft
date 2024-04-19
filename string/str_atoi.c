/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 00:44:55 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 02:06:39 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static t_bool	handle_next_char(int *out, char *buf, int sign, t_str base)
{
	char	*base_str;
	char	*base_current;
	int		digit;

	base_str = str_get(&base);
	base_current = ft_strchr(base_str, *buf);
	if (!*buf || !base_current)
		return (FALSE);
	digit = (int)(base_current - base_str);
	if (*out > INT_MAX / 10 || (*out == INT_MAX / (int)base.len
			&& digit > INT_MAX % (int)base.len))
	{
		if (sign == -1)
			*out = INT_MIN;
		else
			*out = INT_MAX;
		return (FALSE);
	}
	*out *= base.len;
	*out += digit;
	return (TRUE);
}

static void	skip_whitespace(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static void	skip_base(char **str, char *base)
{
	while (ft_strchr(base, **str))
		(*str)++;
}

/// @brief Convert a string to an integer.
/// @param str The string to convert.
/// @param out The integer to write to.
/// @return True if the conversion was successful, false otherwise.
/// @note Will skip leading/trailing whitespace and accept an optional sign.
/// @note Will return false if the string is empty or contains invalid chars.
/// @note Outputs INT_MIN/INT_MAX on overflow.
t_bool	str_atoi(t_str str, t_str base, int *out)
{
	char	*buf;
	int		sign;
	t_bool	ok;

	buf = str_get(&str);
	while (ft_isspace(*buf))
		buf++;
	sign = handle_sign(&buf);
	skip_whitespace(&buf);
	out = 0;
	ok = FALSE;
	if (ft_isdigit(*buf))
		ok = TRUE;
	while (*buf && handle_next_char(out, buf, sign, base))
		buf++;
	skip_base(&buf, str_get(&base));
	if (*out != INT_MAX && *out != INT_MIN)
		*out *= sign;
	skip_whitespace(&buf);
	if (*buf)
		return (FALSE);
	return (ok);
}
