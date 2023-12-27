/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwurster <kwurster@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:17:57 by kwurster          #+#    #+#             */
/*   Updated: 2023/12/27 19:45:08 by kwurster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

typedef int t_bool;
# define TRUE 1
# define FALSE 0

/*
	CLIB
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);

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

typedef t_bool (*t_lst_pred)(t_list *, void *);

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

long long			ft_maxi(long long a, long long b);
long long			ft_mini(long long a, long long b);
unsigned long long	ft_maxu(unsigned long long a, unsigned long long b);
unsigned long long	ft_minu(unsigned long long a, unsigned long long b);
long long			ft_abs(long long num);

size_t	ft_putchar_fd(char c, int fd);
size_t	ft_putfill_fd(char c, int fd, size_t fill);
size_t	ft_putstr_fd(char *s, int fd);
size_t	ft_putendl_fd(char *s, int fd);
size_t	ft_putnbr_fd(int n, int fd);

/*
	PRINTF
*/

int		ft_printf(const char *format, ...);

#endif
