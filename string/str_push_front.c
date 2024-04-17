/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/17 21:57:50 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Insert a character at the beginning of the string.
/// @param str The string to insert to.
/// @param c The character to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_push_front(t_str *str, char c)
{
	str_insert(str, 0, c);
}

/// @brief Insert a character n times at the beginning of the string.
/// @param str The string to insert to.
/// @param c The character to insert.
/// @param n The number of times to insert the character.
/// @warning Check the error flag for memory allocation errors.
void	str_pushn_front(t_str *str, char c, size_t n)
{
	str_insertn(str, 0, c, n);
}

/// @brief Insert a string at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr_front(t_str *str, const char *s)
{
	str_insertstr(str, 0, s);
}

/// @brief Insert a string n times at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @param n The number of times to insert the string.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstrn_front(t_str *str, const char *s, size_t n)
{
	str_insertstrn(str, 0, s, n);
}

/// @brief Insert a string of a given max size at the beginning of the string.
/// @param str The string to insert to.
/// @param s The string to insert.
/// @param n The max size of the string to insert.
/// @warning Check the error flag for memory allocation errors.
void	str_pushstr_sized_front(t_str *str, const char *s, size_t n)
{
	str_insertstr_sized(str, 0, s, n);
}
