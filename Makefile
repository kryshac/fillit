NAME	= fillit
COM		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= main.c ft_min_2d_array.c ft_algoritm.c ft_print_map.c ft_putchar.c \
		ft_remove_elm.c ft_free_map.c ft_malloc_map.c ft_min_size.c \
		ft_lstdel.c ft_putstr.c ft_setzero.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(COM) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(COM) -c $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
