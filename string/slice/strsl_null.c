/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsl_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:07:00 by kwurster          #+#    #+#             */
/*   Updated: 2024/05/07 16:13:54 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_slice.h"

/// @brief Creates a null stringview.
/// @return A null stringview.
t_str_slice	strsl_null(void)
{
	return ((t_str_slice){.len = 0, .str = 0});
}
