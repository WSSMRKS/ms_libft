NAME = libft.a

CLIB_DIR = clib/
GNL_DIR = gnl/
LST_DIR = lst/
OTHER_DIR = other/
PRINTF_DIR = printf/

CLIB_FILES = \
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strcmp.c\
	ft_strdup.c

GNL_FILES = \
	get_next_line.c\
	get_next_line_utils.c

LST_FILES = \
	ft_lstnew_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstadd_back_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\
	ft_lst_first_where_next.c\
	ft_lst_first_where.c\
	ft_lstdel_first.c\
	ft_lstswp_front_where.c\

OTHER_FILES = \
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putfill_fd.c\
	ft_strdist.c\

PRINTF_FILES = \
	# ft_printf.c\

CLIB_SRCS = $(addprefix $(CLIB_DIR), $(CLIB_FILES))
GNL_SRCS = $(addprefix $(GNL_DIR), $(GNL_FILES))
LST_SRCS = $(addprefix $(LST_DIR), $(LST_FILES))
OTHER_SRCS = $(addprefix $(OTHER_DIR), $(OTHER_FILES))
PRINTF_SRCS = $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))

SRCS = $(CLIB_SRCS) $(GNL_SRCS) $(LST_SRCS) $(OTHER_SRCS) $(PRINTF_SRCS)

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
