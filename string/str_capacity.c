/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capacity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 21:48:52 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:15:23 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

static void	heap_str_to_stack_str(t_str *str) {
	char *temp;

	temp = str->large_string;
	ft_strlcpy(&str->small_string, temp, LIBFT_SMALL_STRING_SIZE);
	str->capacity = LIBFT_SMALL_STRING_SIZE;
	str->len = ft_umin(str->len, LIBFT_SMALL_STRING_SIZE - 1);
	free(temp);
}

static t_bool stack_str_to_heap_str(t_str *str, size_t capacity) {
	char *temp;

	temp = malloc(capacity);
	str->err = temp == 0;
	if (str->err)
		return (FALSE);
	ft_strlcpy(temp, &str->small_string, capacity);
	str->large_string = temp;
	return (TRUE);
}

/// @brief Changes the capacity of the string.
/// If an error occurs the error flag of the string is set
/// and the string is left unchanged.
/// @param str String to change the capacity of.
/// @param n New capacity.
/// @return TRUE if the capacity was changed, FALSE otherwise.
t_bool	str_set_capacity(t_str *str, size_t n)
{
	char	*temp;

	if (n <= LIBFT_SMALL_STRING_SIZE) {
		if (str_is_on_heap(*str))
			heap_str_to_stack_str(str);
		return (TRUE);
	}
	if (!str_is_on_heap(*str)) {
		return (stack_str_to_heap_str(str, n));
	}
	temp = ft_reallocstring(str->large_string, n);
	str->err = temp == 0;
	if (str->err)
		return (FALSE);
	str->large_string = temp;
	str->capacity = n;
	str->len = ft_umin(str->len, n - 1);
	return (TRUE);
}


