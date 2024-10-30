NAME 		= so_long

CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror -O3
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a
FT_PRINTF	= ft_printf/libftprintf.a

SRC 		= read_map.c map_checker.c movement.c create_map.c so_long.c so_long_utils.c check_keys.c check_count.c
GNL_SRC		= gnl/get_next_line_utils.c gnl/get_next_line.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_SRC) $(LIBMLX) $(FT_PRINTF) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf minilibx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

clear: fclean
	rm -rf $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re