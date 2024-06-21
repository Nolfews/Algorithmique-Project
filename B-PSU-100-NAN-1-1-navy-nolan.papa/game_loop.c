/*
** EPITECH PROJECT, 2024
** game loop
** File description:
** game loop
*/

#include "include/header.h"

int end_game(char **map, char **map_enemy)
{
    if (ga.nb_x_p1 == 14 || ga.nb_x_p2 == 14) {
        if (ga.nb_x_p1 == 14) {
            my_putstr("Enemy won\n");
            return (1);
        } else {
            my_putstr("I won\n");
            return (1);
        }
    }
    return (0);
}

void game_loop(int argc, char **argv, char **map, char **map_enemy)
{
    ga.nb_atk = 0;
    ga.nb_x_p1 = 0;
    ga.nb_x_p2 = 0;
    while (1) {
        if (ga.nb_atk % 2 == 0)
            print_map(map, map_enemy);
        if (argc == 2) {
            attack(map, map_enemy);
            defense(map, map_enemy);
        }
        if (argc == 3) {
            my_putstr("waiting for enemy's attack...\n\n");
            defense(map, map_enemy);
            attack(map, map_enemy);
        }
        if (end_game(map, map_enemy) == 1)
            break;
    }
}
