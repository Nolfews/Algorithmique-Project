##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

.PHONY : 	all clean fclean re
.DEFAULT_GOAL := all

NAME =		mysh

TESTNAME = 	unit_tests

SRC =		src/main.c						\
			src/pere.c						\
			src/fils.c						\
			src/exit.c						\
			src/env.c						\
			src/error_handler.c				\
			src/set_up_node.c				\

LIB =		lib/my_arraycpy.c				\
			lib/my_compute_power_rec.c		\
			lib/my_compute_square_root.c	\
			lib/my_getnbr.c					\
			lib/my_is_prime.c				\
			lib/my_put_nbr.c				\
			lib/my_putchar.c				\
			lib/my_putstr.c					\
			lib/my_revstr.c					\
			lib/my_strcat.c					\
			lib/my_strcmp.c					\
			lib/my_strcpy.c					\
			lib/my_strlen.c					\
			lib/my_strncat.c				\
			lib/my_strncpy.c				\
			lib/my_swap.c					\

TESTSRC =	tests/test_file.c				\

OBJ = $(SRC:.c=.o)

LIBS = $(LIB:.c=.o)

OBJTEST = 	$(TESTSRC:.c=.o)

CC = gcc

TESTCFLAGS = --coverage -lcriterion

$(NAME) : $(OBJ) $(LIBS)
			$(CC) -o $(NAME) $(OBJ) $(LIBS)

all : $(NAME)

clean :
			rm -f $(OBJ)
			rm -f $(LIBS)

fclean :	clean
			rm -f $(NAME)

re : 		fclean all

unit_tests: fclean all
			gcc -o $(TESTNAME) $(TESTSRC) $(BINNAME) $(TESTCFLAGS)

tests_run: 	unit_tests
			clear
			./$(TESTNAME)

coverage:
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches
