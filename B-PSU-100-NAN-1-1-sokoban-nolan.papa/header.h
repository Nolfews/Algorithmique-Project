/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef HEADETR_H_
    #define HEADETR_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <ncurses.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <unistd.h>

typedef struct coordonne {
    int px;
    int py;
} s_co;

int error_handler(int ac, char **av);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
void game_loop(int ac, char **av);
void find_player(s_co *co, char **map_2d);
void check_key(s_co *co, char **map_2d, int input);
void check_error_in_file(char *map);
void condi_end(char **map, char **map_copy);

#endif /* HEADETR_H_ */
