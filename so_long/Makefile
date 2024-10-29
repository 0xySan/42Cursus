NAME 		= so_long

CC 			= cc
CLONE 		= git clone --depth=1

CFLAGS 		+= -Wall -Wextra -Werror -O3
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

SRC 		= test.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBMLX) $(CLINKS)
	mkdir -p obj
	mv $(OBJ) obj

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(MLX)
	rm -rf obj

fclean: clean
	rm -f $(NAME)
	rm -rf minilibx

clear: fclean
	rm -f -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re