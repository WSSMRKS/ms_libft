/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:58:42 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 00:01:52 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "../types.h"
# include "../libft.h"

/// @brief String Pattern function type.
/// @param str The char to match (or further into the string).
/// @return The length of the pattern matched.
typedef size_t		(*t_str_pattern)(char *str);

char				*str_get(t_str *str);
char				*str_take(t_str *str);
char				*str_get_cloned(t_str str);

t_str				str_base2(void);
t_str				str_base8(void);
t_str				str_base10(void);
t_str				str_base16(void);
t_str				str_base64(void);
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
t_str				str_itoa(int num, t_str base);
void				str_itoa_append(int num, t_str base, t_str *out);
t_str				str_new_clone(const char *s);
t_str				str_new_clone_sized(const char *s, size_t new_len);
t_str				str_new_from_parts(char *s, size_t len);
t_str				str_new_from(char *s, size_t new_len);
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
void				str_pushstr2(t_str *str, t_str s);
void				str_pushstr2_sized(t_str *str, t_str s, size_t len);
void				str_pushstrn2(t_str *str, t_str s, size_t n);
void				str_pushstrn2_sized(t_str *str, t_str s, size_t len,
						size_t n);
void				str_pushstr2_front(t_str *str, t_str s);
void				str_pushstr2_sized_front(t_str *str, t_str s, size_t len);
void				str_pushstrn2_front(t_str *str, t_str s, size_t n);
void				str_pushstrn2_sized_front(t_str *str, t_str s, size_t len,
						size_t n);
char				str_remove(t_str *str, size_t index);
void				str_remove_range(t_str *str, size_t start, size_t end);
t_bool				str_try_set_capacity(t_str *str, size_t n);
t_bool				str_shrink_to_fit(t_str *str);
t_vec				str_split(const t_str *str, t_str_pattern pattern);
void				str_trunc(t_str *str, size_t n);

#endif
