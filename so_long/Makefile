NAME 		= 	so_long

CLONE 		= 	git clone --depth=1

CFLAGS 		+= 	-Wall -Wextra -Werror
CLINKS		= 	-ldl -lglfw -pthread -lm

MLX			= 	minilibx
LIBMLX 		= 	$(MLX)/libmlx42.a
FT_PRINTF_P	= 	ft_dprintf

FT_PRINTF	=	$(FT_PRINTF_P)/dprintf.a
SRC_DIR		= 	src
INC_DIR		= 	include
OBJ_DIR		= 	obj

include Files.mk

SRCS		= $(addsuffix .c,$(addprefix $(SRC_DIR)/,$(FILES)))
OBJS		= $(addsuffix .o,$(addprefix $(OBJ_DIR)/,$(FILES)))

GNL_SRC		=	gnl/get_next_line_utils.c \
				gnl/get_next_line.c

all: $(NAME)

$(NAME): $(LIBMLX) $(OBJS)
	$(MAKE) -C $(FT_PRINTF_P)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(GNL_SRC) $(LIBMLX) $(FT_PRINTF) $(CLINKS)

$(LIBMLX): $(MLX)
	$(MAKE) -C $(MLX)

$(MLX):
	$(CLONE) https://github.com/kodokaii/MLX42.git $(MLX)
	cmake $(MLX) -B $(MLX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(FT_PRINTF_P)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(FT_PRINTF_P)
	rm -rf minilibx
	rm -f $(NAME)

re: fclean all

.PHONY:		all bonus clear clean fclean re