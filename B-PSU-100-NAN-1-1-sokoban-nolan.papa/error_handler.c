/*
** EPITECH PROJECT, 2023
** error handler
** File description:
** error handler
*/

#include "header.h"

void info_jeu(void)
{
    my_putstr("But du jeu :");
    my_putchar('\n');
    my_putstr("pousser les caisses représenté par des X");
    my_putstr(" sur les O pour gagner");
    my_putchar('\n');
    my_putstr("si le jeu est bloqué c'est perdu si tous les X");
    my_putchar('\n');
    my_putstr("sont sur des O le jeu s'arrete");
    my_putchar('\n');
    my_putstr("fonctionnalité :");
    my_putchar('\n');
    my_putstr("espace pour recommencer si jeu en court");
    my_putchar('\n');
    my_putstr("si terminal trop petit n'affiche pas la map et");
    my_putchar('\n');
    my_putstr("demande a l utilisateur d'aggrandir le terminal");
    my_putchar('\n');
}

int error_handler(int ac, char **av)
{
    if (ac > 2 && ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        info_jeu();
        return (1);
    }
    return (0);
}

void check_error_in_file(char *map)
{
    int nb_p = 0;
    int nb_o = 0;
    int nb_x = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] != '#' && map[i] != ' ' && map[i] != 'O' &&
        map[i] != 'P' && map[i] != 'X' && map[i] != '\n' && map[i] != '\0')
            exit(84);
        if (map[i] == 'P')
            nb_p++;
        if (nb_p > 1)
            exit(84);
        if (map[i] == 'O')
            nb_o++;
        if (map[i] == 'X')
            nb_x++;
    }
    if (nb_o != nb_x)
        exit(84);
}
