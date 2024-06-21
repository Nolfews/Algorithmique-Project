##
## EPITECH PROJECT, 2024
## my_navy
## File description:
## Makefile
##

SRC		=		lib/my/my_putnbr.c			\
				lib/my/my_putchar.c			\
				lib/my/my_putstr.c			\
				lib/my/my_strlen.c			\
				lib/my/my_getnbr.c			\
				lib/my/my_cmp.c 			\
				lib/my/my_strdup.c			\
				set_up_map.c				\
				communicator.c				\
				help.c						\
				main.c						\
				set_up_enemy.c				\
				attack.c					\
				defense.c					\
				handler_signaux.c			\
				check_boat.c				\
				game_loop.c					\
				hit_enemy.c					\

OBJ	=	$(SRC:.c=.o)

NAME =	my_navy

CFLAGS += -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f "#*#"

fclean:	clean
	rm -f $(NAME)
re: fclean all
