##
## EPITECH PROJECT, 2024
## stumper
## File description:
## Makefile
##

SRC = src/my_putchar.c\
      src/main.c\
      src/my_putnbr.c\
      src/case_error.c\
      src/str_to_array.c\
      src/print_array.c\
      src/parsing_file.c\
      src/cells_evolution.c\
      src/my_arraycpy.c\
      src/len_tab.c\
      src/get_nb_neighbor.c\
      src/check_if_three_neighbor.c\
      src/check_isolation.c\
      src/check_suffocation.c\
      src/free_array.c\

OBJ = $(SRC:.c=.o)

NAME = gameoflife

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
