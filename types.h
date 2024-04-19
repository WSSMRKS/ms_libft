/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:46:37 by kwurster          #+#    #+#             */
/*   Updated: 2024/04/19 02:40:01 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stddef.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum e_overflow_behavior
{
	ofb_truncate,
	ofb_error
}					t_overflow_behavior;

# ifndef FT_SMALL_VEC
/// The size of the small vec buffer.
#  define FT_SMALL_VEC 48
# endif
# if FT_SMALL_VEC < 1
#  error "FT_SMALL_VEC must be at least 1"
# endif

# ifndef FT_VEC_GROW
/// The factor by which the vec capacity is at least increased when growing.
#  define FT_VEC_GROW 2
# endif
# if FT_VEC_GROW < 1
#  error "FT_VEC_GROW must be at least 1"
# endif

/// @brief A Vec supporting small buffer optimization.
/// When modifying the vec only via its provided methods, reallocations and
/// out-of-bounds-access are handled automatically.
/// When malloc errors happen the 'mem_err' flag is set and
/// the vec is left in a valid state.
/// @warning Mixing vecs/arrays with different element sizes leads to UB.
typedef struct s_vec
{
	union
	{
		/// @brief Small vec buffer.
		/// @warning May only be modified/read directly if 'heap' = FALSE.
		char		_small_buf[FT_SMALL_VEC];
		struct
		{
			/// @brief Heap allocated vec buffer.
			/// @warning May only be modified/read directly if 'heap' = TRUE.
			char	*_large_buf;
			/// @brief Capacity of the heap vec buffer (number of elements).
			/// @warning May only be modified/read directly if 'heap' = TRUE.
			/// Use 'vec_capacity()' instead for a safe read.
			size_t	_capacity;
		};
	};
	/// @brief Length of the vec.
	size_t			len;
	/// @brief Size of a single element in the vec.
	size_t			element_size: sizeof(size_t) * 8 - 2;
	/// @brief Heap flag.
	size_t			heap: 1;
	/// @brief Memory error flag.
	size_t			mem_err: 1;
}					t_vec;

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

# define BASE2 "01"
# define BASE8 "01234567"
# define BASE10 "0123456789"
# define BASE16 "0123456789abcdef"
# define BA64 "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

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

/// A string view is a non-owning reference to a string.
/// It is used to pass strings around without copying them.
/// It is not safe to use a string view after the string it references has been
/// modified or destroyed.
/// @warning A string view is not null-terminated.
/// @warning Do not modify the string view.
/// @warning Do not destroy the string view.
typedef t_str		t_str_view;

#endif
