/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:45:21 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 17:20:28 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*out;

	len = ft_strlen(s) + 1;
	out = malloc(len);
	if (!out)
		return (0);
	ft_memcpy(out, s, len);
	return (out);
}
