SRCS_FILE = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c

BONUS_FILE = 	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c \

SRCS = $(addprefix ./,$(SRCS_FILE))

BONUS = $(addprefix ./,$(BONUS_FILE))

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

NAME = libft.a

%.o: %.c ./libft.h
		@gcc -c -o $@ $< -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar rc $@ $(OBJ)

clean:
		@rm -f $(OBJ)
		@rm -f $(OBJ_BONUS)

fclean: clean
		@rm -f $(NAME)

all: $(NAME)

re: fclean all

bonus:	$(OBJ_BONUS)
		@ar rc $(NAME) $(OBJ_BONUS)

.PHONY: all fclean clean re bonus
