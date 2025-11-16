CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRC_DIR = src
SRC = ft_printf.c ft_printf_numbers.c ft_printf_strings.c

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

INCLUDE = -I.  -I./inc/   #инклюд относительно мейкфайла

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c  | $(OBJ_DIR)
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
