/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:25:11 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 00:31:47 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/// @brief Copy a string.
/// @param dst The destination string.
/// @param src The source string.
/// @warning Check the error flag for memory allocation errors.
void	str_copy(t_str *dst, t_str src)
{
	str_copy_sized(dst, src, src.len);
}

/// @brief Copy a string with a given max size.
/// @param dst The destination string.
/// @param src The source string.
/// @param n The max size of the copied string.
/// @warning Check the error flag for memory allocation errors.
void	str_copy_sized(t_str *dst, t_str src, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*dst);
	n = ft_umin(n, src.len);
	if (n >= cap)
		if (!str_try_grow(dst, n - cap + 1))
			return ;
	buf = str_get(dst);
	ft_memcpy(buf, str_get(&src), n);
	dst->len = n;
	buf[n] = 0;
}

/// @brief Concatenate a string.
/// @param dst The destination string.
/// @param src The source string.
/// @warning Check the error flag for memory allocation errors.
void	str_cat(t_str *dst, t_str src)
{
	str_cat_sized(dst, src, src.len);
}

/// @brief Concatenate a string with a given max size.
/// @param dst The destination string.
/// @param src The source string.
/// @param n The max size of the source string.
/// @warning Check the error flag for memory allocation errors.
void	str_cat_sized(t_str *dst, t_str src, size_t n)
{
	char	*buf;
	size_t	cap;

	cap = str_capacity(*dst);
	n = ft_umin(n, src.len);
	if (dst->len + n >= cap)
		if (!str_try_grow(dst, dst->len + n - cap + 1))
			return ;
	buf = str_get(dst);
	ft_memcpy(buf + dst->len, str_get(&src), n);
	dst->len += n;
	buf[dst->len] = 0;
}
