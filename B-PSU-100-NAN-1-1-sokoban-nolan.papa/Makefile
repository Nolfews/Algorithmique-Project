##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC 	=	main.c          \
			my_sokoban.c	\
			error_handler.c \
			game_play.c		\
			lib/my_put_nbr.c\
			lib/my_putstr.c \
			lib/my_putchar.c\
			lib/my_strlen.c \
			end_game.c 		\

BINNAME = 	my_sokoban

CFLAGS += -g

OBJ		= 	$(SRC:.c=.o)

all: 		$(BINNAME)

$(BINNAME):	$(OBJ)
			gcc -o $(BINNAME) $(OBJ) -lncurses

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(BINNAME)

re:			fclean all
