/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** check_if_three_neighbor
*/

#include "../includes/my.h"

int check_if_three_neighbor(int i, int j, char **array)
{
    int nb_neighbor = 0;

    get_nb_neighbor(i, j, array, &nb_neighbor);
    if (array[i][j] == 'X')
        return (0);
    if (nb_neighbor == 3)
        return (1);
    return (0);
}
