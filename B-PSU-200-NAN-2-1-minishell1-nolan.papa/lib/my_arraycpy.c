/*
** EPITECH PROJECT, 2024
** my arraycpy
** File description:
** my arraycpy
*/

#include "../header.h"

char **my_arraycpy(char **array)
{
    char **copy;
    int j = 0;
    int i = 0;

    for (j = 0; array[j] != NULL; j++)
    copy = malloc(sizeof(char *) * (j + 1));
    for (i = 0; array[i] != NULL; i++) {
        copy[i] = my_strcpy(array[i]);
    }
    copy[i] = NULL;
    return copy;
}
