/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:56:53 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 21:56:49 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Remove the last character from the string.
/// @param str The string to remove from.
/// @return The removed character.
char	str_pop(t_str *str)
{
	char	*buf;
	char	out;

	if (str->len == 0)
		return (0);
	buf = str_get(str);
	out = buf[--(str->len)];
	buf[str->len] = 0;
	return (out);
}

/// @brief Remove a character at a given index from the string.
/// @param str The string to remove from.
/// @param index The index of the character to remove.
/// @return The removed character.
char	str_remove(t_str *str, size_t index)
{
	char	*buf;
	char	out;

	if (index >= str->len)
		return (0);
	buf = str_get(str);
	out = buf[index];
	ft_memmove(buf + index, buf + index + 1, str->len - index);
	str->len--;
	return (out);
}

/// @brief Remove a range of characters from the string.
/// @param str The string to remove from.
/// @param start The start index of the range to remove.
/// @param end The end index of the range to remove.
void	str_remove_range(t_str *str, size_t start, size_t end)
{
	char	*buf;

	start = ft_umin(start, str->len);
	end = ft_umin(end, str->len);
	buf = str_get(str);
	ft_memmove(buf + start, buf + end, str->len - end + 1);
	str->len -= end - start;
}

/// @brief Remove n characters from the end of the string.
/// @param str The string to remove from.
/// @param n The number of characters to remove.
void	str_trunc(t_str *str, size_t n)
{
	n = ft_umin(n, str->len);
	str_get(str)[str->len - n] = 0;
	str->len -= n;
}

/// @brief Clear the string.
/// @param str The string to clear.
void	str_clear(t_str *str)
{
	str_get(str)[0] = 0;
	str->len = 0;
	str->mem_err = FALSE;
}
