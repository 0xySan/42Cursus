SRCS_FILE = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c

SRCS = $(addprefix srcs/,$(SRCS_FILE))

OBJ = $(SRCS:.c=.o)

NAME = libft.a

%.o: %.c includes/ft.h
		@gcc -c -o $@ $< -I includes -Wall -Wextra -Werror

$(NAME): $(OBJ)
		@ar rc $@ $(OBJ)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all fclean clean re