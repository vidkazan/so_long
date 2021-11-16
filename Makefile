NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror -I./mlx

LIBS = -L./mlx -lmlx -framework OpenGL -framework AppKit

SRC = so_long_1.c so_long_2.c so_long_3.c so_long_utils1.c so_long_utils2.c main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

mlx:
	make -C mlx

$(NAME): $(OBJ) mlx
	$(CC) -o $(NAME) $(FLAGS) $(LIBS) $(OBJ)

%.o:%.c so_long.h
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	make clean -C mlx
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re mlx
