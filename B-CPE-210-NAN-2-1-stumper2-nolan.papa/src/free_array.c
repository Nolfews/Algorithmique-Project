/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** free_array function
*/

#include <stdio.h>
#include <stdlib.h>
#include "../includes/my.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
