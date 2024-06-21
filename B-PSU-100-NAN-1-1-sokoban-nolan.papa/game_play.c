/*
** EPITECH PROJECT, 2023
** game play
** File description:
** game play
*/

#include "header.h"

static void condi_find_player(s_co *co, char **map_2d, int i, int j)
{
    if (map_2d[i][j] == 'P') {
        co->px = j;
        co->py = i;
    }
}

void find_player(s_co *co, char **map_2d)
{
    for (int i = 0; map_2d[i] != NULL; i++) {
        for (int j = 0; map_2d[i][j] != '\0'; j++) {
            condi_find_player(co, map_2d, i , j);
        }
    }
}

static void go_top(s_co *co, char **map_2d)
{
    char c = map_2d[co->py - 1][co->px];

    if ( c == ' ' || c == 'O') {
        map_2d[co->py - 1][co->px] = 'P';
        map_2d[co->py][co->px] = ' ';
        co->py = co->py - 1;
    }
    if (c == 'X') {
        if (map_2d[co->py - 2][co->px] == ' '
        || map_2d[co->py - 2][co->px] == 'O') {
            map_2d[co->py - 1][co->px] = 'P';
            map_2d[co->py - 2][co->px] = 'X';
            map_2d[co->py][co->px] = ' ';
            co->py = co->py - 1;
        }
    }
}

static void go_bot(s_co *co, char **map_2d)
{
    char c = map_2d[co->py + 1][co->px];

    if (c == ' ' || c == 'O') {
        map_2d[co->py + 1][co->px] = 'P';
        map_2d[co->py][co->px] = ' ';
        co->py = co->py + 1;
    }
    if (c == 'X') {
        if (map_2d[co->py + 2][co->px] == ' '
        || map_2d[co->py + 2][co->px] == 'O') {
            map_2d[co->py + 1][co->px] = 'P';
            map_2d[co->py + 2][co->px] = 'X';
            map_2d[co->py][co->px] = ' ';
            co->py = co->py + 1;
        }
    }
}

static void go_left(s_co *co, char **map_2d)
{
    char c = map_2d[co->py][co->px - 1];

    if (c == ' ' || c == 'O') {
        map_2d[co->py][co->px - 1] = 'P';
        map_2d[co->py][co->px] = ' ';
        co->px = co->px - 1;
    }
    if (c == 'X') {
        if (map_2d[co->py][co->px - 2] == ' '
        || map_2d[co->py][co->px - 2] == 'O') {
            map_2d[co->py][co->px - 1] = 'P';
            map_2d[co->py][co->px - 2] = 'X';
            map_2d[co->py][co->px] = ' ';
            co->px = co->px - 1;
        }
    }
}

static void go_right(s_co *co, char **map_2d)
{
    char c = map_2d[co->py][co->px + 1];

    if (c == ' ' || c == 'O') {
        map_2d[co->py][co->px + 1] = 'P';
        map_2d[co->py][co->px] = ' ';
        co->px = co->px + 1;
    }
    if (c == 'X') {
        if (map_2d[co->py][co->px + 2] == ' '
        || map_2d[co->py][co->px + 2] == 'O') {
            map_2d[co->py][co->px + 1] = 'P';
            map_2d[co->py][co->px + 2] = 'X';
            map_2d[co->py][co->px] = ' ';
            co->px = co->px + 1;
        }
    }
}

void check_key(s_co *co, char **map_2d, int input)
{
    if (input == 0403) {
        go_top(co, map_2d);
    }
    if (input == 0402) {
        go_bot(co, map_2d);
    }
    if (input == 0404) {
        go_left(co, map_2d);
    }
    if (input == 0405) {
        go_right(co, map_2d);
    }
}
