/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:17:57 by kwurster          #+#    #+#             */
/*   Updated: 2024/03/26 01:39:58 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef long long t_ll;
typedef unsigned long long t_ull;

/*
	CLIB
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t from, size_t to);
void	*ft_reallocarray(void *ptr, size_t from, size_t nmemb, size_t size);
char	*ft_reallocstring(char *ptr, size_t to);

/*
	GNL
*/

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

char	*get_next_line(int fd);

/*
	LIST
*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef t_bool	(*t_lst_pred)(t_list*, void*);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *node);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *node);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lst_first_where(t_list *lst, t_lst_pred pred, void *pred_data);
t_list	*ft_lst_first_where_next(t_list *lst, t_lst_pred pred, void *pred_data);
t_list	*ft_lstswp_front_where(t_list **lst, t_lst_pred pred, void *pred_data);
void	ft_lstswp_front(t_list **lst, t_list *node, t_list *prev);
void	ft_lstdel_first(t_list **lst, void (*del)(void*));

/*
	MATH
*/

t_bool	ft_safe_mult(t_ll a, t_ll b, t_ll max, t_ll *result);
t_bool	ft_safe_umult(t_ull a, t_ull b, t_ull max, t_ull *result);
t_ll	ft_max(t_ll a, t_ll b);
t_ll	ft_min(t_ll a, t_ll b);
t_ull	ft_umax(t_ull a, t_ull b);
t_ull	ft_umin(t_ull a, t_ull b);
t_ull	ft_abs(t_ll num, t_ll min);

/*
	OTHER
*/

char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strdist(const char *start, const char *end);

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putfill_fd(char c, int fd, size_t fill);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);

/*
	STRING
*/

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t len);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_str_notchr(const char *s, int c);
char	*ft_strr_notchr(const char *s, int c);

// must at least be sizeof(char *) + 1
# define LIBFT_SMALL_STRING_SIZE 16
# define LIBFT_STRING_GROW_FACTOR 2

/// @brief A string that can grow and shrink and is stored on the stack if it is small enough.
typedef struct s_str
{
	/// @brief Length of the string.
	size_t		len;
	/// @brief Buffer size of the string.
	size_t		capacity;
	/// @brief Union of a small string buffer and a large string buffer.
	union {
        char	small_string[LIBFT_SMALL_STRING_SIZE];
        char	*large_string;
    };
	/// @brief Error flag.
	t_bool		err;
}	t_str;

char	*str_get(t_str *str);
char	*str_take(t_str* str);
char	*str_get_cloned(t_str str);
t_str	str_new_from(char *s, size_t len);
t_str	str_new_cloned(const char *s, size_t len);
t_str	str_new_repeat(const char *s, size_t len, size_t n);
t_str	str_empty();
t_str	str_empty_with_capacity(size_t n);
t_str	str_clone(t_str str);
t_bool	str_is_on_heap(t_str str);
t_bool	str_is_empty(t_str str);
void	str_destroy(t_str *str);
void	str_clear(t_str *str);
t_bool	str_grow(t_str *str, size_t min_growth);
t_bool	str_set_capacity(t_str *str, size_t n);
t_bool	str_shrink_to_fit(t_str *str);
void	str_push(t_str *str, char c);
void	str_pushn(t_str *str, char c, size_t n);
void	str_pushstr(t_str *str, const char *s);
void	str_pushstrn(t_str *str, const char *s, size_t n);
void	str_push_front(t_str *str, char c);
void	str_pushn_front(t_str *str, char c, size_t n);
void	str_pushstr_front(t_str *str, const char *s);
void	str_pushstrn_front(t_str *str, const char *s, size_t n);
void	str_trunc(t_str *str, size_t len);
char	str_pop(t_str *str);
char	str_remove(t_str *str, size_t index);
void	str_remove_range(t_str *str, size_t start, size_t end);
void	str_insert(t_str *str, size_t index, char c);
void	str_insertn(t_str *str, size_t index, char c, size_t n);
void	str_insertstr(t_str *str, size_t index, const char *s);
void	str_insertstrn(t_str *str, size_t index, const char *s, size_t n);
t_str	str_split_off(t_str *str, size_t index);
void	str_replace_range(t_str *str, size_t start, size_t end, const char *s);
void	str_replace_str(t_str *str, const char *old, const char *new);
void	str_replace_first_str(t_str *str, const char *old, const char *new);
void	str_replace_last_str(t_str *str, const char *old, const char *new);
void	str_replace(t_str *str, char old, char new);
void	str_replace_first(t_str *str, char old, char new);
void	str_replace_last(t_str *str, char old, char new);
void	str_trim(t_str *str);
void	str_trim_start(t_str *str);
void	str_trim_end(t_str *str);
void	str_trim_set(t_str *str, const char *set);
void	str_trim_start_set(t_str *str, const char *set);
void	str_trim_end_set(t_str *str, const char *set);
void	str_trim_not_set(t_str *str, const char *set);
void	str_trim_start_not_set(t_str *str, const char *set);
void	str_trim_end_not_set(t_str *str, const char *set);
void	str_trim_not(t_str *str, char c);
void	str_trim_start_not(t_str *str, char c);
void	str_trim_end_not(t_str *str, char c);
void	str_upper(t_str *str);
void	str_lower(t_str *str);
void	str_reverse(t_str *str);
void	str_map(t_str *str, void (*f)(char*));
void	str_mapi(t_str *str, void (*f)(size_t, char*));
void	str_map_rev(t_str *str, void (*f)(char*));
void	str_mapi_rev(t_str *str, void (*f)(size_t, char*));
// TODO: use recursive algorithm for str_filter_map to avoid quadratic complexity
void	str_filter_map(t_str *str, t_bool (*f)(char*));
void	str_filter_mapi(t_str *str, t_bool (*f)(size_t, char*));
void	str_filter_map_rev(t_str *str, t_bool (*f)(char*));
void	str_filter_mapi_rev(t_str *str, t_bool (*f)(size_t, char*));

/*
	PRINTF
*/

// int		ft_printf(const char *format, ...);

#endif
