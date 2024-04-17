/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:27:59 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 22:37:51 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Append a character to the string.
/// @param str The string to append to.
/// @param c The character to append.
/// @warning Check the error flag for memory allocation errors.
void	str_push(t_str *str, char c)
{
	char	*buf;

	if (str->len + 1 >= str_capacity(*str))
		if (!str_try_grow(str, 1))
			return ;
	buf = str_get(str);
	buf[str->len++] = c;
	buf[str->len] = 0;
}

/// @brief Append a character n times to the string.
/// @param str The string to append to.
/// @param c The character to append.
/// @param n The number of times to append the character.
/// @warning Check the error flag for memory allocation errors.
void	str_pushn(t_str *str, char c, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*str);
	if (str->len + n >= cap)
		if (!str_try_grow(str, str->len + n - cap + 1))
			return ;
	buf = str_get(str);
	while (n--)
		buf[str->len++] = c;
	buf[str->len] = 0;
}

/// @brief Append a string to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr(t_str *str, const char *s)
{
	char	*buf;

	buf = str_get(str);
	while (*s && str->len + 1 < str_capacity(*str))
		buf[str->len++] = *s++;
	buf[str->len] = 0;
	if (*s)
	{
		if (!str_try_grow(str, ft_strlen(s)))
			return ;
		str_pushstr(str, s);
	}
}

/// @brief Append a string n times to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @param n The number of times to append the string.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn(t_str *str, const char *s, size_t n)
{
	char	*buf;
	size_t	s_len;
	size_t	cap;

	s_len = ft_strlen(s);
	cap = str_capacity(*str);
	if (str->len + s_len * n >= cap)
		if (!str_try_grow(str, str->len + s_len * n - cap + 1))
			return ;
	buf = str_get(str);
	while (n--)
	{
		ft_memcpy(buf + str->len, s, s_len);
		str->len += s_len;
	}
	buf[str->len] = 0;
}

/// @brief Append a string of a given max size to the string.
/// @param str The string to append to.
/// @param s The string to append.
/// @param n The maximum number of characters to append.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr_sized(t_str *str, const char *s, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*str);
	if (str->len + n >= cap)
		if (!str_try_grow(str, str->len + n - cap + 1))
			return ;
	buf = str_get(str);
	while (*s && n--)
		buf[str->len++] = *s++;
	buf[str->len] = 0;
}
