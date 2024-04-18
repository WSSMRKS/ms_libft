NAME = libft.a

LIBC_FILES = \
	libc/ft_atoi.c\
	libc/ft_bzero.c\
	libc/ft_calloc.c\
	libc/ft_isalnum.c\
	libc/ft_isalpha.c\
	libc/ft_isascii.c\
	libc/ft_isdigit.c\
	libc/ft_isprint.c\
	libc/ft_memchr.c\
	libc/ft_memcmp.c\
	libc/ft_memcpy.c\
	libc/ft_memdup.c\
	libc/ft_memmove.c\
	libc/ft_memset.c\
	libc/ft_memswap.c\
	libc/ft_realloc.c\
	libc/ft_tolower.c\
	libc/ft_toupper.c\

GNL_FILES = \
	gnl/get_next_line_utils.c\
	gnl/get_next_line.c\

LST_FILES = \
	lst/ft_lst_first_where_next.c\
	lst/ft_lst_first_where.c\
	lst/ft_lstadd_back.c\
	lst/ft_lstadd_front.c\
	lst/ft_lstclear.c\
	lst/ft_lstdel_first.c\
	lst/ft_lstdelone.c\
	lst/ft_lstiter.c\
	lst/ft_lstlast.c\
	lst/ft_lstmap.c\
	lst/ft_lstnew.c\
	lst/ft_lstsize.c\
	lst/ft_lstswp_front_where.c\

MATH_FILES = \
	math/ft_min_max_abs.c\
	math/ft_safe_mult.c\

OTHER_FILES = \
	other/bit.c\
	other/bool.c\
	other/ft_putchar_fd.c\
	other/ft_putendl_fd.c\
	other/ft_putfill_fd.c\
	other/ft_putnbr_fd.c\
	other/ft_putstr_fd.c\

STRING_GENERIC_FILES = \
	string/generic/ft_itoa.c\
	string/generic/ft_split.c\
	string/generic/ft_strchr.c\
	string/generic/ft_strcmp.c\
	string/generic/ft_strdist.c\
	string/generic/ft_strdup.c\
	string/generic/ft_striteri.c\
	string/generic/ft_strjoin.c\
	string/generic/ft_strlcat.c\
	string/generic/ft_strlcpy.c\
	string/generic/ft_strlen.c\
	string/generic/ft_strmapi.c\
	string/generic/ft_strncmp.c\
	string/generic/ft_strnstr.c\
	string/generic/ft_strrchr.c\
	string/generic/ft_strtrim.c\
	string/generic/ft_substr.c\

STRING_FILES = \
	string/str_capacity.c\
	string/str_clone.c\
	string/str_cmp.c\
	string/str_copy.c\
	string/str_destroy.c\
	string/str_empty.c\
	string/str_get.c\
	string/str_grow.c\
	string/str_insert.c\
	string/str_new_clone.c\
	string/str_new_from.c\
	string/str_new_repeat.c\
	string/str_push_front.c\
	string/str_push.c\
	string/str_remove.c\

VEC_FILES = \
	vec/vec_capacity.c\
	vec/vec_clone.c\
	vec/vec_cmp.c\
	vec/vec_copy.c\
	vec/vec_destroy.c\
	vec/vec_empty.c\
	vec/vec_extract.c\
	vec/vec_get.c\
	vec/vec_grow.c\
	vec/vec_insert.c\
	vec/vec_new_clone.c\
	vec/vec_new_from.c\
	vec/vec_new_repeat.c\
	vec/vec_pop.c\
	vec/vec_push_front.c\
	vec/vec_push.c\
	vec/vec_pushvec_sized.c\
	vec/vec_pushvec.c\
	vec/vec_remove.c\
	vec/vec_rotate.c\
	vec/vec_swap.c\

FT_PRINTF_FILES = \
	printf/fmt_c.c\
	printf/fmt_hex.c\
	printf/fmt_hexup.c\
	printf/fmt_int.c\
	printf/fmt_ptr.c\
	printf/fmt_str.c\
	printf/fmt_uint.c\
	printf/formatting.c\
	printf/ft_printf.c\
	printf/percent_char.c\

SRCS = $(LIBC_FILES) $(GNL_FILES) $(LST_FILES) $(MATH_FILES) $(OTHER_FILES) $(STRING_GENERIC_FILES) $(STRING_FILES) $(FT_PRINTF_FILES) $(VEC_FILES)

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
