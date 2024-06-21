/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** main
*/

#include "include/header.h"
g_all ga;

static void print_p1(void)
{
    my_putstr("my_pid: ");
    my_putnbr((int)getpid());
    my_putstr("\n\nen attente de signaux...\n\n");
}

static void print_p2(void)
{
    my_putstr("my_pid: ");
    my_putnbr((int)getpid());
    my_putstr("\n\n");
}

int main(int argc, char **argv)
{
    int nb = help(argc, argv);
    char **map;
    char **map_enemy = create_map_enemy_2d("map/map_player2.txt");

    if (nb == 84)
        return (84);
    if (nb == 1)
        return (0);
    if (argc == 2) {
        map = set_up_map(argv[1]);
        if (map == NULL)
            return (84);
    } else {
        map = set_up_map(argv[2]);
        if (map == NULL)
            return (84);
    }
    communication(argc, argv, map, map_enemy);
    return (0);
}
