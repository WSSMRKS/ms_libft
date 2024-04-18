/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 06:19:16 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/18 23:49:53 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "../libft.h"

typedef void		(*t_vec_map)(const void *from, void *to);
typedef void		(*t_vec_mapi)(const t_vec *from, t_vec *to, size_t i);
typedef void		(*t_vec_iter)(void *element);
typedef void		(*t_vec_iteri)(t_vec *vec, size_t i);

void				*vec_get(const t_vec *vec);
void				*vec_get_at(const t_vec *vec, size_t index);
void				*vec_get_last(const t_vec *vec);
void				*vec_take(t_vec *vec);
void				*vec_get_cloned(const t_vec *vec);

size_t				vec_capacity(const t_vec *vec);
void				vec_clear(t_vec *vec);
t_vec				vec_clone(const t_vec *vec);
t_vec				vec_clone_sized(const t_vec *vec, size_t new_len);
void				vec_copy(t_vec *dst, const t_vec *src);
void				vec_copy_sized(t_vec *dst, const t_vec *src,
						size_t new_len);
void				vec_cat(t_vec *dst, const t_vec *src);
void				vec_cat_sized(t_vec *dst, const t_vec *src, size_t n);
void				vec_destroy(t_vec *vec);
t_str				vec_display(t_vec *vec, t_str (*display)(void *));
t_str				vec_debug(t_vec *vec, t_str (*debug)(void *));
t_vec				vec_empty(size_t element_size);
t_vec				vec_empty_with_capacity(size_t element_size, size_t n);
t_vec				vec_extract_range(t_vec *vec, size_t start, size_t end);
t_bool				vec_try_grow(t_vec *vec, size_t min_growth);
t_bool				vec_identical(const t_vec *vec1, const t_vec *vec2);
t_bool				vec_cmp(const t_vec *vec1, const t_vec *vec2);
void				vec_insert(t_vec *vec, size_t index, void *data);
void				vec_insertn(t_vec *vec, size_t index, void *data, size_t n);
void				vec_insertarr(t_vec *vec, size_t index, void *arr,
						size_t len);
void				vec_insertvec(t_vec *vec, size_t index, const t_vec *data);
void				vec_insertvec_sized(t_vec *vec, size_t index,
						const t_vec *data, size_t n);
void				vec_iter(t_vec *vec, t_vec_iter iter);
void				vec_iteri(t_vec *vec, t_vec_iteri iteri);
t_vec				vec_map(const t_vec *vec, t_vec_map map,
						size_t element_size);
t_vec				vec_mapi(const t_vec *vec, t_vec_mapi mapi,
						size_t element_size);
t_vec				vec_new_from(void *arr, size_t element_size, size_t len);
t_vec				vec_new_clone(const void *arr, size_t element_size,
						size_t len);
t_vec				vec_new_repeat(void *arr, size_t element_size, size_t len,
						size_t n);

t_vec				vec_pop(t_vec *vec);
t_vec				vec_pop_front(t_vec *vec);
void				vec_push(t_vec *vec, void *data);
void				vec_push_front(t_vec *vec, void *data);
void				vec_pushn(t_vec *vec, void *data, size_t n);
void				vec_pushn_front(t_vec *vec, void *data, size_t n);
void				vec_pusharr(t_vec *vec, void *arr, size_t len);
void				vec_pusharr_front(t_vec *vec, void *arr, size_t len);
void				vec_pusharrn(t_vec *vec, void *arr, size_t len, size_t n);
void				vec_pusharrn_front(t_vec *vec, void *arr, size_t len,
						size_t n);
void				vec_pushvec(t_vec *vec, const t_vec *data);
void				vec_pushvec_front(t_vec *vec, const t_vec *data);
void				vec_pushvecn(t_vec *vec, const t_vec *data, size_t n);
void				vec_pushvecn_front(t_vec *vec, const t_vec *data, size_t n);
void				vec_pushvec_sized(t_vec *vec, const t_vec *data,
						size_t len);
void				vec_pushvec_front_sized(t_vec *vec, const t_vec *data,
						size_t len);
void				vec_pushvecn_sized(t_vec *vec, const t_vec *data,
						size_t len, size_t n);
void				vec_pushvecn_front_sized(t_vec *vec, const t_vec *data,
						size_t len, size_t n);
void				vec_remove(t_vec *vec, size_t index);
void				vec_remove_last(t_vec *vec);
void				vec_remove_range(t_vec *vec, size_t start, size_t end);
void				vec_shiftleft(t_vec *vec, size_t n);
void				vec_shiftright(t_vec *vec, size_t n);
t_bool				vec_rotate(t_vec *vec, size_t n);
t_bool				vec_rrotate(t_vec *vec, size_t n);
t_bool				vec_try_set_capacity(t_vec *vec, size_t n);
t_bool				vec_shrink_to_fit(t_vec *vec);
void				vec_swap(t_vec *vec1, t_vec *vec2);
void				vec_swap_at(t_vec *vec1, size_t index1, t_vec *vec2,
						size_t index2);
void				vec_trunc(t_vec *vec, size_t n);

#endif
