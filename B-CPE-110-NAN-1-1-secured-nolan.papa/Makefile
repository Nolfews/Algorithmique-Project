##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC 	=	hash.c									\
			ht_delete.c								\
			ht_dump.c								\
			ht_insert.c								\
			ht_search.c								\
			lib/my_put_nbr.c						\
			lib/my_putchar.c						\
			lib/my_putstr.c							\
			lib/my_strlen.c							\
			lib/my_strcpy.c							\
			lib/my_strcmp.c							\

TESTSRC =	tests/test_hash.c						\

OBJTEST = 	$(TEST:.c=.o)

OBJ		= 	$(SRC:.c=.o)

BINNAME = 	libhashtable.a

TESTNAME = 	unit_tests


TESTCFLAGS = --coverage -lcriterion

all: 		$(BINNAME)

$(BINNAME):	$(OBJ)
			ar rc -o $(BINNAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINNAME)

re:			fclean all

unit_tests: fclean all
			gcc -o $(TESTNAME) $(TESTSRC) $(BINNAME) $(TESTCFLAGS)

tests_run: 	unit_tests
			clear
			./$(TESTNAME)

coverage:
			gcovr --exclude tests/
			gcovr --exclude tests/ --branches
