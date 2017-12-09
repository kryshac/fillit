COM = gcc
FLAGS = -Wall -Wextra -Werror

all: main
	$(COM) $(FLAGS) -o main main.c
