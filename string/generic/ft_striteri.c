/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:28:37 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/02 05:14:45 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(unsigned char *s, void (*f)(unsigned int, unsigned char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
		f(i++, s++);
}
