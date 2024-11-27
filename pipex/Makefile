NAME = pipex
EXECUTABLE = $PWD/$(NAME)

SRCS = 	pipex.c pipex_utils.c pipex_cmds.c check_pipex.c
NUMB2 = 0
PERCENT = 0
RED = $(shell tput bold setaf 1)
GREEN = $(shell tput setaf 2)
PURPLE = $(shell tput setaf 5)
BLUE = $(shell tput setaf 6)
LIGHTBLUE = $(shell tput -Txterm setaf 4)
BOLD = $(shell tput bold)
RESET = $(shell tput -Txterm sgr0)
OBJS = $(SRCS:.c=.o)
NB = $(shell echo $(SRCS) | wc -w)
NB3 = $(shell ls | grep .o | wc -w)
NB4 = $(shell awk 'BEGIN { print $(NB) - $(NB3) }')

CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_SRC		=	gnl/get_next_line_utils.c \
				gnl/get_next_line.c

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -s -C libft
	@echo "$(BOLD)$(RED)Libft compiled$(RESET)"
	@make --no-print-directory -s -C ft_dprintf
	@echo "$(BOLD)$(RED)dprintf compiled$(RESET)"
	@if [ -f ./$(NAME) ]; then echo "$(BOLD)$(BLUE)Executable already exists.$(RESET)"; else echo "$(BOLD)$(BLUE)Created the executable : $(NAME)$(RESET)"; fi
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a ft_dprintf/dprintf.a $(GNL_SRC)
	@echo "$(BOLD)$(PURPLE)Finished the compilation of the Makefile$(RESET)"

%.o: %.c
	$(eval NUMB2=$(shell echo $$(($(NUMB2)+1))))
	$(eval NB4=$(shell echo $$(( $(NB4) ))))
	$(eval PERCENT=$(shell echo $$(( $(NUMB2) * 100 / $(NB4) ))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BOLD)$(PURPLE)[Percent : "$(PERCENT).0%"] $(BOLD)$(GREEN)    ~Compiling $< : $@$(RESET)"

clean:
	@make --no-print-directory -s clean -C libft
	@echo "$(BOLD)$(BLUE)Finished cleaning libft$(RESET)"
	@make --no-print-directory -s clean -C ft_dprintf
	@echo "$(BOLD)$(BLUE)Finished cleaning dprintf$(RESET)"
	@rm -f $(OBJS)
	@echo "$(BOLD)$(RED)Removed all objs$(RESET)"
	@echo "$(BOLD)$(BLUE)Finished cleaning all$(RESET)"

fclean: clean
	@make --no-print-directory -s fclean -C libft
	@echo "$(BOLD)$(LIGHTBLUE)Finished fcleaning libft$(RESET)"
	@make --no-print-directory -s fclean -C ft_dprintf
	@echo "$(BOLD)$(LIGHTBLUE)Finished fcleaning dprintf$(RESET)"
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)Removed the executable : $(NAME)$(RESET)"
	@echo "$(BOLD)$(LIGHTBLUE)Finished fcleaning all$(RESET)"

re: fclean all

.PHONY: all clean fclean re