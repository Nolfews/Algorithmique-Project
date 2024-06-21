/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <signal.h>

typedef struct co_pos {
    int len_boat;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} co_p;

typedef struct glob {
    int my_pid;
    int nb_atk;
    int nb_x_p1;
    int nb_x_p2;
    int co_x_move;
    int co_y_move;
    int trans;
} g_all;

extern g_all ga;

int my_putnbr(int nb);
int my_getnbr(char *str);
int my_putstr(char const *str);
int my_putchar(char c);
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_cmp(char const *s1, char const *s2);
int help(int argc, char **argv);
int main(int argc, char **argv);
char **set_up_map(char *path);
int communication(int argc, char **argv, char **map, char **map_enemy);
void handler(int signo, siginfo_t *structure, void *ucontext);
char **create_map_2d(char *filpath);
int print_map(char **map, char **map_enemy);
char **create_map_enemy_2d(char *filpath);
int defense(char **map, char **map_enemy);
int attack(char **map, char **map_enemy);
void handler(int signo, siginfo_t *structure, void *ucontext);
void handler_p2(int signo, siginfo_t *structure, void *ucontext);
int check_boat2(char **map, int i, int j, int nb_2);
int check_boat3(char **map, int i, int j, int nb_3);
int check_boat4(char **map, int i, int j, int nb_4);
int check_boat5(char **map, int i, int j, int nb_5);
void game_loop(int argc, char **argv, char **map, char **map_enemy);
void hit_enemy(int y, int x, char **map_enemy, int i);

#endif /* !HEADER_H_ */
