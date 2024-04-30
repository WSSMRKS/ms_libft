/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsl_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:50:44 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 15:09:38 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_slice.h"

/// @brief Removes the last character from the stringview.
/// @param s The stringview to remove from.
/// @return The removed character.
char	strsl_pop(t_str_slice *s)
{
	if (!s->len)
		return (0);
	return (s->str[--s->len]);
}
