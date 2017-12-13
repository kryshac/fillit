NAME	= main
COM		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= main.c ft_min_2d_array.c ft_algoritm.c ft_print_map.c ft_putchar.c \
		ft_remove_elm.c
OBJ		= $(SRC:%.c=%.o)

all: $(NAME)
	./main valid_sample.fillit

$(NAME): $(OBJ)
	$(COM) -o $@ $^

$(OBJ): $(SRC)
	$(COM) -c $^

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
