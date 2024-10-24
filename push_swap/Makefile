NAME = push_swap

SRCS = 	ft_atoi.c \
		input_validation.c \
		push_swap.c \
		push_swap_ops.c \
		sort_small.c \
		sort_stack.c \
		utils.c \
		stack_ops.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re