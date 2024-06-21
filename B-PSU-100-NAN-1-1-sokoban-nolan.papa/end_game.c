/*
** EPITECH PROJECT, 2023
** end game
** File description:
** end game
*/

#include "header.h"

int comp_end(char **map, char **map_copy, int j, int nb)
{
    for (int i = 0; map[j][i] != '\0'; i++) {
        if (map[j][i] == 'X' && map_copy[j][i] == 'O') {
            nb++;
        }
    }
    return (nb);
}

int condi_o(char **map_copy, int j, int i, int nb)
{
    if (map_copy[j][i] == 'O') {
        nb++;
    }
    return (nb);
}

static int compt_o(char **map_copy)
{
    int nb = 0;

    for (int j = 0; map_copy[j] != NULL; j++) {
        for (int i = 0; map_copy[j][i] != '\0'; i++) {
            nb = condi_o(map_copy, j, i, nb);
        }
    }
    return (nb);
}

static void aff_loose(char **map)
{
        refresh();
        usleep(10000);
        free(map);
        endwin();
        exit(1);
}

static void loose_check(char **map, int j, int i)
{
    char top = map[j - 1][i];
    char right = map[j][i + 1];
    char bot = map[j - 1][i];
    char left = map[j][i - 1];

    if (map[j][i] == 'X' && top == '#' && right == '#')
        aff_loose(map);
    if (map[j][i] == 'X' && right == '#' && bot == '#')
        aff_loose(map);
    if (map[j][i] == 'X' && bot == '#' && left == '#')
        aff_loose(map);
    if (map[j][i] == 'X' && left == '#' && top == '#')
        aff_loose(map);
}

static void map_stuck(char **map, char **map_copy, int nb_o)
{
    for (int j = 1; map[j] != NULL; j++) {
        for (int i = 1; map[j][i] != '\0'; i++) {
            loose_check(map, j, i);
        }
    }
}

void condi_end(char **map, char **map_copy)
{
    int nb = 0;
    int nb_o = compt_o(map_copy);

    map_stuck(map, map_copy, nb_o);
    for (int j = 0; map[j] != NULL; j++) {
        nb = comp_end(map, map_copy, j , nb);
    }
    if (nb == nb_o) {
        refresh();
        usleep(1000000);
        free(map);
        free(map_copy);
        endwin();
        exit(0);
    }
}
