/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:52:33 by kwurster          #+#    #+#             */
/*   Updated: 2024/06/21 01:03:04 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include <stdlib.h>

void	array_free(void *array, size_t len, size_t element_size,
			void (*destroy)(void *))
{
	size_t	i;

	if (destroy)
	{
		i = 0;
		while (i < len)
		{
			destroy(array + i * element_size);
			i++;
		}
	}
	free(array);
}
