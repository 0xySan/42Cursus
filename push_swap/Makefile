NAME = push_swap
EXECUTABLE = $PWD/$(NAME)

SRCS = 	ft_atoi.c input_validation.c push_swap.c push_swap_ops.c push_swap_ops_2.c push_swap_ops_3.c put_pos.c get_pos.c get_cost.c sort_utils.c sort_small.c sort_five.c ft_strlen.c sort_stack.c utils.c stack_ops.c split.c

OBJS = $(SRCS:.c=.o)
NUMB2 = 0
PERCENT = 0
RED = $(shell tput bold setaf 1)
GREEN = $(shell tput setaf 2)
PURPLE = $(shell tput setaf 5)
BLUE = $(shell tput setaf 6)
LIGHTBLUE = $(shell tput -Txterm setaf 4)
YELLOW = $(shell tput -Txterm setaf 3)
BOLD = $(shell tput bold)
BOLD = $(shell tput bold)
UNDERLINE = $(shell tput smul)
RESET = $(shell tput -Txterm sgr0)
OBJS = $(SRCS:.c=.o)
NB = $(shell echo $(SRCS) | wc -w)
NB3 = $(shell ls | find . -type f -name \*.o | wc -w)
NB4 = $(shell awk 'BEGIN { print $(NB) - $(NB3) }')

CC = gcc
CFLAGS = -Werror -Wunused -Wall

all: $(NAME)

$(NAME): $(OBJS)
	@if [ -f ./$(NAME) ]; then echo "$(BOLD)$(BLUE)Executable already exists.$(RESET)"; else echo "$(BOLD)$(BLUE)Created the executable : $(NAME)$(RESET)"; fi
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD)$(PURPLE)Finished the compilation of the Makefile$(RESET)"

%.o: %.c
	$(eval NUMB2=$(shell echo $$(($(NUMB2)+1))))
	$(eval NB4=$(shell echo $$(( $(NB4) ))))
	$(eval PERCENT=$(shell echo $$(( $(NUMB2) * 100 / $(NB4) ))))
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BOLD)$(PURPLE)[    $(BOLD)$(RED)Percent $(BOLD)$(PURPLE): $(BOLD)$(UNDERLINE)$(YELLOW)"$(PERCENT).0%"$(RESET)$(BOLD)$(PURPLE)\t]$(BOLD)$(GREEN)\t\t~Compiling $< : $@$(RESET)"

clean:
	@rm -f $(OBJS)
	@echo "$(BOLD)$(RED)Removed all objs$(RESET)"
	@echo "$(BOLD)$(BLUE)Finished cleaning all$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(RED)Removed the executable : $(NAME)$(RESET)"
	@echo "$(BOLD)$(LIGHTBLUE)Finished fcleaning all$(RESET)"

re: fclean all

.PHONY: all clean fclean re