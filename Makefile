NAME = push_swap

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -r

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

LIBFT_PATH = assets/libft
LIBFT_LIB_PATH = assets/libft/libft.a

HEADERS	= -I $(LIBFT_PATH)/include/ -I ./include

SRC_FILES = fn_actions.c fn_algorithms.c fn_errors.c \
			fn_utils.c ft_arg_check.c ft_create_stack.c \
			ft_fill_stats.c ft_move_cheapest.c init.c push_swap.c

SRC := $(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

ORANGE = \033[1;38;5;208m
RESET = \033[0m
U_LINE = \033[4m
YELLOW = \033[1;38;5;226m

all: $(LIBFT_LIB_PATH) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_LIB_PATH) $(HEADERS) -o $@
	@echo "\n$(ORANGE)$(U_LINE)⭐️ $(NAME): Compiled ⭐️$(RESET) \n"

$(LIBFT_LIB_PATH):
	@$(MAKE) -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@echo "$(YELLOW)$(NAME) Compiling:$(RESET) $(notdir $<)"

clean:
	@$(REMOVE) $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(REMOVE) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_LIB_PATH)
