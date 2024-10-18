SRCS_FILE = ft_printf.c \
	    ft_ltoa.c \
	    ft_ptoa.c \
	    ft_putstr.c \
	    ft_utoa.c \
	    ft_count_unsigned.c \
	    ft_printf.c \
	    ft_putchar.c \
	    ft_ultoa.c

SRCS = $(addprefix ./,$(SRCS_FILE))

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a

%.o: %.c ./libprintf.h
		@gcc -c -o $@ $< -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar rc $@ $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all fclean clean re
