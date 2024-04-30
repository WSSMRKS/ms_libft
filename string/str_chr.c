/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:01:32 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 14:37:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

const char	*str_chr(const t_str *str, char c)
{
	return (ft_strchr(cstr_ref(str), c));
}

const char	*str_rchr(const t_str *str, char c)
{
	size_t		i;
	const char	*cstr;

	i = str->len + 1;
	cstr = cstr_ref(str);
	while (i--)
		if (cstr[i] == c)
			return (cstr + i);
	return (0);
}
