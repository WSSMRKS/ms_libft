/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 00:16:30 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 22:35:48 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Insert a character at a given index into the string.
/// @param str The string to insert into.
/// @param index The index to insert the character at.
/// @param c The character to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_insert(t_str *str, size_t index, char c)
{
	str_insertn(str, index, c, 1);
}

/// @brief Insert a character n times at a given index into the string.
/// @param str The string to insert into.
/// @param index The index to insert the character at.
/// @param c The character to insert.
/// @param n The number of times to insert the character.
/// @warning Check the error flag for memory allocation errors.
void	str_insertn(t_str *str, size_t index, char c, size_t n)
{
	char	*buf;
	size_t	cap;

	if (index > str->len)
		return ;
	cap = str_capacity(*str);
	if (str->len + n >= cap)
		if (!str_try_grow(str, str->len + n - cap + 1))
			return ;
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	ft_memset(buf + index, c, n);
	str->len += n;
}

/// @brief Insert a string at a given index into the string.
/// @param str The string to insert into.
/// @param index The index to insert the string at.
/// @param s The string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_insertstr(t_str *str, size_t index, const char *s)
{
	str_insertstr_sized(str, index, s, ft_strlen(s));
}

/// @brief Insert a string of a given max size at a given index into the string.
/// @param str The string to insert into.
/// @param index The index to insert the string at.
/// @param s The string to insert.
/// @param n The max size of the string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_insertstr_sized(t_str *str, size_t index, const char *s, size_t n)
{
	char	*buf;
	size_t	cap;

	if (index > str->len)
		return ;
	cap = str_capacity(*str);
	if (str->len + n >= cap)
		if (!str_try_grow(str, str->len + n - cap + 1))
			return ;
	buf = str_get(str);
	ft_memmove(buf + index + n, buf + index, str->len - index + 1);
	buf = buf + index;
	str->len += n;
	while (*s && n--)
		*buf++ = *s++;
}

/// @brief Insert a string n times at a given index into the string.
/// @param str The string to insert into.
/// @param index The index to insert the string at.
/// @param s The string to insert.
/// @param n The number of times to insert the string.
/// @warning Check the error flag for memory allocation errors.
void	str_insertstrn(t_str *str, size_t index, const char *s, size_t n)
{
	char	*buf;
	size_t	s_len;
	size_t	cap;

	if (index > str->len)
		return ;
	s_len = ft_strlen(s);
	cap = str_capacity(*str);
	if (str->len + n * s_len >= cap)
		if (!str_try_grow(str, str->len + n * s_len - cap + 1))
			return ;
	buf = str_get(str);
	ft_memmove(buf + index + n * s_len, buf + index, str->len - index + 1);
	while (n--)
		ft_memcpy(buf + index + n * s_len, s, s_len);
	str->len += s_len * n;
}
