/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:00:00 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 14:00:58 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

t_bool	str_atoi(const t_str *str, t_str_slice base, int *out,
		t_overflow_behavior ofb)
{
	return (strsl_atoi(str_view(str), base, out, ofb));
}
