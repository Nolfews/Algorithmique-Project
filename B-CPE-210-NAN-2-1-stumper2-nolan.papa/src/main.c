/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** main
*/

#include "../includes/my.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    char **array;

    case_error(argc, argv);
    array = cells_evolution(argv[1], atoi(argv[2]));
    print_array(array);
    free_array(array);
    return 0;
}
