/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsl_trim_inplace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:48:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 15:11:09 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_slice.h"

/// @brief Removes leading and trailing whitespace from a stringview.
/// @param s The stringview to trim.
void	strsl_trim_inplace(t_str_slice *s)
{
	return (strsl_trim_start_inplace(s), strsl_trim_end_inplace(s));
}

/// @brief Removes trailing whitespace from a stringview.
/// @param s The stringview to trim.
void	strsl_trim_end_inplace(t_str_slice *s)
{
	while (s->len && ft_isspace(s->str[s->len - 1]))
		s->len--;
}

/// @brief Removes leading whitespace from a stringview.
/// @param s The stringview to trim.
void	strsl_trim_start_inplace(t_str_slice *s)
{
	while (s->len && ft_isspace(*s->str))
	{
		s->str++;
		s->len--;
	}
}
