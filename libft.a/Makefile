SRCS_FILE = $(wildcard ft_*.c) // to change wildcard

SRCS = $(addprefix ./,$(SRCS_FILE))

OBJ = $(SRCS:.c=.o)

NAME = libft.a

%.o: %.c ./libft.h
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