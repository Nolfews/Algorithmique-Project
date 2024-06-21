/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** defense
*/

#include "include/header.h"

int hit(int x, int y, char **map)
{
    my_putstr("result: ");
    my_putchar(x + 'A' - 1);
    my_putnbr(y - 1);
    y += 1;
    x = (x - 1) * 2 + 2;
    if (map[y][x] >= '2' && map[y][x] <= '5') {
        map[y][x] = 'x';
        ga.nb_x_p1++;
        my_putstr("hit\n\n");
        return (1);
    }
    if (map[y][x] == 'x' || map[y][x] == 'o') {
        my_putstr(":missed\n\n");
        return (0);
    }
    if (map[y][x] == '.') {
        map[y][x] = 'o';
        my_putstr(":missed\n\n");
        return 0;
    }
}

int defense(char **map, char **map_enemy)
{
    int x;
    int y;

    while (ga.trans >= 0) {
    }
    x = -(ga.trans);
    ga.trans = 0;
    kill(ga.my_pid, 10);
    while (ga.trans >= 0) {
    }
    y = -(ga.trans);
    ga.trans = 0;
    usleep(1000);
    kill(ga.my_pid, 10 + (hit(y, x, map) * 2));
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
    }
    return 0;
}
