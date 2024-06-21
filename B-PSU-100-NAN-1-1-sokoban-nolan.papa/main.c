/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "header.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        return (84);
    } else if (error_handler(ac, av) == 84) {
        return (84);
    } else {
        game_loop(ac, av);
    }
    return (0);
}
