/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:58:42 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/30 15:28:14 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include "../libft.h"
# include "../types.h"
# include "slice/str_slice.h"

const char	*cstr_ref(const t_str *str);
char		*cstr_mut(t_str *str);
char		*cstr_take(t_str *str);
char		*cstr_clone(const t_str *str);

size_t		str_capacity(const t_str *str);
void		str_clear(t_str *str);
t_str		str_clone(const t_str *str);
void		str_replace(t_str *dst, t_str_slice src);
void		str_cat(t_str *dst, t_str_slice src);
void		str_destroy(t_str *str);
t_str		str_empty(void);
t_str		str_empty_with_capacity(size_t n);
t_bool		str_try_grow(t_str *str, size_t min_growth);
t_bool		str_identical(const t_str *str1, const t_str *str2);
t_bool		str_eq(const t_str *str1, const t_str *str2);
t_bool		str_starts_with(t_str str, const t_str *pattern);
t_bool		str_atoi(const t_str *str, t_str_slice base, int *out,
				t_overflow_behavior ofb);
const char	*str_chr(const t_str *str, char c);
const char	*str_rchr(const t_str *str, char c);
void		str_insert(t_str *str, size_t at, char c);
void		str_insertn(t_str *str, size_t at, char c, size_t n);
void		str_insertstr(t_str *str, size_t at, t_str_slice s);
void		str_insertstrn(t_str *str, size_t at, t_str_slice s, size_t n);
t_str		str_itoa(int num, t_str_slice base);
void		str_itoa_cat(int num, t_str_slice base, t_str *out);
t_str		str_clone_from(t_str_slice s);
t_str		str_from_parts(char *str, size_t len);
t_str		str_from(char *str, size_t new_len);
t_str		str_repeat_from(t_str_slice s, size_t n);
char		str_pop(t_str *str);
void		str_push(t_str *str, char c);
void		str_push_front(t_str *str, char c);
void		str_pushn(t_str *str, char c, size_t n);
void		str_pushn_front(t_str *str, char c, size_t n);
void		str_pushstr(t_str *str, t_str_slice s);
void		str_pushstr_front(t_str *str, t_str_slice s);
void		str_pushstrn(t_str *str, t_str_slice s, size_t n);
void		str_pushstrn_front(t_str *str, t_str_slice s, size_t n);
char		str_remove(t_str *str, size_t at);
void		str_remove_range(t_str *str, size_t start, size_t end);
t_bool		str_try_set_capacity(t_str *str, size_t n);
t_bool		str_shrink_to_fit(t_str *str);
void		str_trim(t_str *str);
void		str_trim_end(t_str *str);
void		str_trim_start(t_str *str);
void		str_trunc(t_str *str, size_t new_len);

#endif
