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
	libc/ft_isspace.c\
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
	gnl/get_next_line_finish.c\

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
	math/iabs.c\
	math/imax.c\
	math/imin.c\
	math/imult.c\
	math/umax.c\
	math/umin.c\
	math/umult.c\

OTHER_FILES = \
	other/ft_putchar_fd.c\
	other/ft_putendl_fd.c\
	other/ft_putfill_fd.c\
	other/ft_putnbr_fd.c\
	other/ft_putstr_fd.c\
	other/util.c\

CSTR_FILES = \
	string/cstr/ft_itoa.c\
	string/cstr/ft_split.c\
	string/cstr/ft_strchr.c\
	string/cstr/ft_strcmp.c\
	string/cstr/ft_strdist.c\
	string/cstr/ft_strdup.c\
	string/cstr/ft_striteri.c\
	string/cstr/ft_strjoin.c\
	string/cstr/ft_strlcat.c\
	string/cstr/ft_strlcpy.c\
	string/cstr/ft_strlen.c\
	string/cstr/ft_strmapi.c\
	string/cstr/ft_strncmp.c\
	string/cstr/ft_strnstr.c\
	string/cstr/ft_strrchr.c\
	string/cstr/ft_strtrim.c\
	string/cstr/ft_substr.c\

STRING_SLICE_FILES = \
	string/slice/base2.c\
	string/slice/base8.c\
	string/slice/base10.c\
	string/slice/base16.c\
	string/slice/base64.c\
	string/slice/str_slice.c\
	string/slice/strsl_atoi.c\
	string/slice/strsl_chr.c\
	string/slice/strsl_cmp.c\
	string/slice/strsl_move.c\
	string/slice/strsl_null.c\
	string/slice/strsl_pop.c\
	string/slice/strsl_split.c\
	string/slice/strsl_trim_inplace.c\
	string/slice/strsl_trim.c\
	string/slice/strsl_trunc.c\

STRING_FILES = \
	string/str_atoi.c\
	string/str_capacity.c\
	string/str_chr.c\
	string/str_clone.c\
	string/str_cmp.c\
	string/str_copy.c\
	string/str_destroy.c\
	string/str_empty.c\
	string/str_fold.c\
	string/str_grow.c\
	string/str_insert.c\
	string/str_itoa.c\
	string/str_new_clone.c\
	string/str_new_from.c\
	string/str_new_repeat.c\
	string/str_push.c\
	string/str_pushstr.c\
	string/str_ref.c\
	string/str_remove.c\
	string/str_trim.c\
	string/str_util.c\

VEC_FILES = \
	vec/vec_capacity.c\
	vec/vec_clone.c\
	vec/vec_cmp.c\
	vec/vec_copy.c\
	vec/vec_cstr.c\
	vec/vec_cstr2.c\
	vec/vec_destroy.c\
	vec/vec_display.c\
	vec/vec_empty.c\
	vec/vec_extract.c\
	vec/vec_fold.c\
	vec/vec_get.c\
	vec/vec_grow.c\
	vec/vec_insert.c\
	vec/vec_iter.c\
	vec/vec_new_clone.c\
	vec/vec_new_from.c\
	vec/vec_pop.c\
	vec/vec_push_front.c\
	vec/vec_push.c\
	vec/vec_pushvec_sized.c\
	vec/vec_pushvec.c\
	vec/vec_remove.c\
	vec/vec_remove2.c\
	vec/vec_reverse.c\
	vec/vec_rotate.c\
	vec/vec_str_append_to_all.c\
	vec/vec_str.c\
	vec/vec_str2.c\
	vec/vec_strsl.c\
	vec/vec_swap.c\
	vec/vec_uninit.c\
	vec/vec_util.c\

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
	printf/ft_printf_fd.c\
	printf/percent_char.c\

FS_FILES = \
	fs/file.c\
	fs/find_perror.c\
	fs/find.c\

ENV_FILES = \
	env/env.c\

ARRAY_FILES = \
	array/array.c\

SRCS = $(LIBC_FILES) $(GNL_FILES) $(LST_FILES) $(MATH_FILES) $(OTHER_FILES) $(CSTR_FILES) $(STRING_SLICE_FILES) $(STRING_FILES) $(FT_PRINTF_FILES) $(VEC_FILES) $(FS_FILES) $(ENV_FILES) $(ARRAY_FILES)

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -flto -O3
# CFLAGS = -Wall -Wextra -Werror -g -Og -fanalyzer

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
