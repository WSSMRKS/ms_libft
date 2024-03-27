/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_push_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 23:54:20 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/25 23:56:03 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	str_push_front(t_str *str, char c)
{
	str_insert(str, 0, c);
}

void	str_pushn_front(t_str *str, char c, size_t n)
{
	str_insertn(str, 0, c, n);
}

void	str_pushstr_front(t_str *str, const char *s)
{
	str_insertstr(str, 0, s);
}

void	str_pushstrn_front(t_str *str, const char *s, size_t n)
{
	str_insertstrn(str, 0, s, n);
}