##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC 	=	main.c									\
			add.c									\
			del.c									\
			disp.c									\
			sort.c									\
			my_strcpy.c								\
			my_strlen.c								\
			my_putstr.c								\
			my_put_nbr.c							\
			my_putchar.c							\
			my_getnbr.c								\
			my_strcmp.c								\
			invsort.c								\

BINNAME = 	organized

OBJ		= 	$(SRC:.c=.o)

all: 		$(BINNAME)

$(BINNAME):	$(OBJ)
			gcc -o $(BINNAME) $(OBJ) -lshell -L./libshell/

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINNAME)

re:			fclean all
