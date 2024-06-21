/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** nb_neighbor
*/

#include <string.h>
#include "../includes/my.h"

void get_nb_neighbor(int i, int j, char **array, int *nb_neighbor)
{
    if (i - 1 >= 0 && j - 1 >= 0 && array[i - 1][j - 1] == 'X')
        (*nb_neighbor) += 1;
    if (i - 1 >= 0 && array[i - 1][j] == 'X')
        (*nb_neighbor) += 1;
    if (i - 1 >= 0 && j + 1 <= strlen(array[i]) - 1
        && array[i - 1][j + 1] == 'X')
        (*nb_neighbor) += 1;
    if (j + 1 <= strlen(array[i]) - 1 && array[i][j + 1] == 'X')
        (*nb_neighbor) += 1;
    if (i + 1 <= len_tab(array) - 2 && j + 1 <=
        strlen(array[i]) - 1 && array[i + 1][j + 1] == 'X')
        (*nb_neighbor) += 1;
    if (i + 1 <= len_tab(array) - 2 && array[i + 1][j] == 'X')
        (*nb_neighbor) += 1;
    if (i + 1 <= len_tab(array) - 2 && j - 1 >= 0 &&
        array[i + 1][j - 1] == 'X')
        (*nb_neighbor) += 1;
    if (j - 1 >= 0 && array[i][j - 1] == 'X')
        (*nb_neighbor) += 1;
}
