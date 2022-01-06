NAME = so_long

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = -L libft/ -lft

HEADERS = so_long.h get_next_line.h

MLX = -framework OpenGL -framework AppKit -lmlx 

SRC =	so_long.c					\
		treatment_map.c				\
		treatment_images.c			\
		treatment_keys.c			\
		treatment_exit.c			\
		gnl/get_next_line.c			\
		gnl/get_next_line_utils.c

OBJ = $(SRC:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(MLX) $(LIBFT) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make fclean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re