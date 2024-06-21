/*
** EPITECH PROJECT, 2024
** exit
** File description:
** exit
*/

#include "../header.h"

void my_exit(char **arg, int status)
{
    int nb;

    if (arg[1] != NULL) {
        nb = my_getnbr(arg[1]);
        exit(nb);
    }
    exit(status);
}
