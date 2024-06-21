/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** attack
*/

#include "include/header.h"

int error_in_game(size_t len, char *str)
{
    if (len != 3)
        return 84;
    if (str[0] < 'A' || str[0] > 'H')
        return 84;
    if (str[1] < '1' || str[1] > '8')
        return 84;
    ga.co_x_move = str[1] - '1';
    ga.co_y_move = str[0] - 'A';
    return 0;
}

void stock_info(void)
{
    char *str = NULL;
    size_t len;
    size_t nb = 5;

    ga.co_x_move = 0;
    ga.co_y_move = 0;
    while (1) {
        len = getline(&str, &nb, stdin);
        if (error_in_game(len, str) == 0) {
            break;
        } else {
            my_putstr("\nwrong position\n\n");
            my_putstr("attack: ");
        }
    }
}

static void show_result(void)
{
    if (ga.trans == 1)
        my_putstr(":missed\n");
    else
        my_putstr(":hit\n");
}

int attack(char **map, char **map_enemy)
{
    my_putstr("\nattack: ");
    stock_info();
    for (int i = 0; i <= ga.co_x_move; i++) {
        kill(ga.my_pid, 10);
        usleep(1000);
    }
    kill(ga.my_pid, 12);
    pause();
    for (int i = 0; i <= ga.co_y_move; i++) {
        kill(ga.my_pid, 10);
        usleep(1000);
    }
    kill(ga.my_pid, 12);
    ga.trans = 0;
    pause();
    my_putstr("\nresult: ");
    my_putchar(ga.co_y_move + 'A');
    my_putnbr(ga.co_x_move + 1);
    show_result();
    return 0;
}
