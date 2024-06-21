##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile.
##

SRC 	=	main.c						\

BINNAME = 	fozzbazz					\

OBJ	= 	$(SRC:.c=.o)

OBJTEST = 	$(TEST:.c=.o)

all: 		$(BINNAME)

$(BINNAME):	$(OBJ)
	gcc -o $(BINNAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(BINNAME)

re:		fclean all
