/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** cells evolution
*/

#include "../includes/my.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static void find_in_line(char **cell_before, char **cell_actual, int i)
{
    for (int j = 0; j < strlen(cell_before[i]); j++) {
        if (check_if_three_neighbor(i, j, cell_before) == 1) {
            cell_actual[i][j] = 'X';
        }
        if (check_isolation(i, j, cell_before) == 1) {
            cell_actual[i][j] = '.';
        }
        if (check_suffocation(i, j, cell_before) == 1) {
            cell_actual[i][j] = '.';
        }
    }
}

char **cells_evolution(char *filepath, int nb_iter)
{
    char **cell_before = parsing_file(filepath);
    char **cell_actual = my_arraycpy(cell_before);

    for (int nb = 0; nb < nb_iter; nb++) {
        for (int i = 0; cell_before[i] != NULL; i++) {
            find_in_line(cell_before, cell_actual, i);
        }
        cell_before = my_arraycpy(cell_actual);
    }
    free_array(cell_before);
    return cell_actual;
}
