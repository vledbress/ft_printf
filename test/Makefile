CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = test
LIB = -L../ -lftprintf
SRC = main.c

INCLUDE = -I../ #инклюд относительно мейкфайла

all: $(NAME)

$(NAME) : $(SRC)
	$(CC) $(INCLUDE) $(CFLAGS) $(SRC) $(LIB) -o $@	


fclean: clean
	rm $(NAME)

f: $(NAME)
	./$<

re: fclean all

.PHONY: all clean fclean re f
