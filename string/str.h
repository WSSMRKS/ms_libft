/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:58:42 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 00:32:42 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "../libft.h"

# ifndef FT_SMALL_STR
/// The size of the small string buffer.
#  define FT_SMALL_STR 24
# endif
# if FT_SMALL_STR < 1
#  error "FT_SMALL_STR must be at least 1"
# endif

# ifndef FT_STR_GROW
/// The factor by which the string capacity is at least increased when growing.
#  define FT_STR_GROW 2
# endif
# if FT_STR_GROW < 1
#  error "FT_STR_GROW must be at least 1"
# endif

/// @brief A SSO-enabled, growable, safe string type.
/// When modifying the string only via its provided methods, reallocations,
/// out-of-bounds-access and null-terminations are handled automatically.
/// When malloc errors happen the 'mem_err' flag is set and
/// the string is left in a valid state.
typedef struct s_str
{
	union
	{
		/// @brief Small string buffer.
		/// @warning May only be modified/read directly if 'heap' = FALSE.
		char		_small_string[FT_SMALL_STR];
		struct
		{
			/// @brief Heap allocated string buffer.
			/// @warning May only be modified/read directly if 'heap' = TRUE.
			char	*_large_string;
			/// @brief Capacity of the heap string buffer.
			/// @warning May only be modified/read directly if 'heap' = TRUE.
			/// Use 'str_capacity()' instead for a safe read.
			size_t	_capacity;
		};
	};
	/// @brief Length of the string.
	size_t			len: sizeof(size_t) * 8 - 2;
	/// @brief Heap flag.
	size_t			heap: 1;
	/// @brief Memory error flag.
	size_t			mem_err: 1;
}					t_str;

char				*str_get(t_str *str);
char				*str_take(t_str *str);
char				*str_get_cloned(t_str str);

size_t				str_capacity(t_str str);
void				str_clear(t_str *str);
t_str				str_clone(t_str str);
t_str				str_clone_sized(t_str str, size_t new_len);
int					str_cmp(t_str str1, t_str str2);
void				str_copy(t_str *dst, t_str src);
void				str_copy_sized(t_str *dst, t_str src, size_t n);
void				str_cat(t_str *dst, t_str src);
void				str_cat_sized(t_str *dst, t_str src, size_t n);
void				str_destroy(t_str *str);
t_str				str_empty(void);
t_str				str_empty_with_capacity(size_t n);
t_bool				str_try_grow(t_str *str, size_t min_growth);
t_bool				str_identical(t_str str1, t_str str2);
void				str_insert(t_str *str, size_t index, char c);
void				str_insertn(t_str *str, size_t index, char c, size_t n);
void				str_insertstr(t_str *str, size_t index, const char *s);
void				str_insertstrn(t_str *str, size_t index, const char *s,
						size_t n);
void				str_insertstr_sized(t_str *str, size_t index, const char *s,
						size_t n);
t_str				str_new_clone_sized(const char *s, size_t new_len);
t_str				str_new_from(char *s, size_t len);
t_str				str_new_from_sized(char *s, size_t new_len);
t_str				str_new_repeat(const char *s, size_t len, size_t n);
t_str				str_new_repeat_sized(const char *s, size_t s_len,
						size_t new_len, size_t n);
char				str_pop(t_str *str);
void				str_push(t_str *str, char c);
void				str_push_front(t_str *str, char c);
void				str_pushn(t_str *str, char c, size_t n);
void				str_pushn_front(t_str *str, char c, size_t n);
void				str_pushstr(t_str *str, const char *s);
void				str_pushstr_front(t_str *str, const char *s);
void				str_pushstrn(t_str *str, const char *s, size_t n);
void				str_pushstr_sized(t_str *str, const char *s, size_t n);
void				str_pushstr_sized_front(t_str *str, const char *s,
						size_t n);
char				str_remove(t_str *str, size_t index);
void				str_remove_range(t_str *str, size_t start, size_t end);
t_bool				str_try_set_capacity(t_str *str, size_t n);
t_bool				str_shrink_to_fit(t_str *str);
void				str_trunc(t_str *str, size_t n);

#endif
