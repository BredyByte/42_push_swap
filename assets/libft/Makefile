NAME = libft.a

CC = cc
CFLAGS =  -Wall -Wextra -Werror
ARFLAGS = ar -rcs
REMOVE = rm -rf

OBJ_PATH = obj
SRC_PATH = src
INC_PATH = include

SRC_FILES = ft_abs.c ft_lstlast.c ft_split.c \
ft_atof.c ft_lstnew.c ft_strchr.c \
ft_atoi.c ft_lstsize.c ft_strcmp.c \
ft_bzero.c ft_memchr.c ft_strdup.c \
ft_calloc.c ft_memcmp.c ft_striteri.c \
ft_dstrlen.c ft_memcpy.c ft_strjoin.c \
ft_free.c ft_memmove.c ft_strlcat.c \
ft_isalnum.c ft_memset.c ft_strlcpy.c \
ft_isalpha.c ft_printf.c ft_strlen.c \
ft_isascii.c ft_putchar.c ft_strmapi.c \
ft_isdigit.c ft_putchar_fd.c ft_strncmp.c \
ft_isprint.c ft_putdec.c ft_strndup.c \
ft_isspace.c ft_putdeclong.c ft_strnstr.c \
ft_itoa.c ft_putendl_fd.c ft_strrchr.c \
ft_itoalong.c ft_puthexa.c ft_strtrim.c \
ft_lstadd_back.c ft_putnbr_fd.c ft_substr.c \
ft_lstadd_front.c ft_putstr.c ft_tolower.c \
ft_lstclear.c ft_putstr_fd.c ft_toupper.c \
ft_lstdelone.c ft_putvoid.c get_next_line.c

SRC := $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))

HEADERS = -I $(INC_PATH)

.PHONY: all clean fclean re

.SILENT: all clean fclean re

VIOLET = \033[38;5;129m
RESET = \033[0m
U_LINE = \033[4m
PINK = \033[1;38;5;206m

all: $(NAME)

$(NAME): $(OBJ)
	@$(ARFLAGS) $@ $(OBJ)
	@echo "\n$(VIOLET)$(U_LINE)🌸 $(NAME): Compiled 🌸 $(RESET) \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$(PINK)libft Compiling:$(RESET) $(notdir $<)"

clean:
	@$(REMOVE) $(OBJ_PATH)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all
