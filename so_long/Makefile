NAME 		= so_long

CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror -O3 -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a
FT_PRINTF_P	= ft_printf

FT_PRINTF	=	$(FT_PRINTF_P)/libftprintf.a

SRC 		= 	read_map.c \
				map_checker.c \
				movement.c \
				create_map.c \
				so_long.c \
				so_long_utils.c \
				check_keys.c \
				check_count.c \
				free_utils.c

GNL_SRC		=	gnl/get_next_line_utils.c \
				gnl/get_next_line.c

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(MAKE) -C $(FT_PRINTF_P)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_SRC) $(LIBMLX) $(FT_PRINTF) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(FT_PRINTF_P)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(FT_PRINTF_P)
	rm -rf minilibx
	rm -f $(NAME)

clear: fclean
	rm -rf $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re