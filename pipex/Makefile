NAME = pipex

SRCS = 	pipex.c pipex_utils.c pipex_cmds.c check_pipex.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_SRC		=	gnl/get_next_line_utils.c \
				gnl/get_next_line.c

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a ft_printf/libftprintf.a $(GNL_SRC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re