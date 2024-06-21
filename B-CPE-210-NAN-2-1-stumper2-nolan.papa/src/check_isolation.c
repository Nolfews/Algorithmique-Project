/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** check isolation
*/

#include "../includes/my.h"

int check_isolation(int i, int j, char **array)
{
    int nb_neighbor = 0;

    get_nb_neighbor(i, j, array, &nb_neighbor);
    if (array[i][j] == '.')
        return 0;
    if (nb_neighbor <= 1)
        return 1;
    return 0;
}
