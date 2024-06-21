/*
** EPITECH PROJECT, 2024
** my arraycpy
** File description:
** my arraycpy
*/

#include "../includes/my.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **my_arraycpy(char **array)
{
    char **copy;
    int j = 0;
    int i = 0;
    int k = 0;

    for (; array[j] != NULL; j++);
    copy = malloc(sizeof(char *) * (j + 1));
    for (int i = 0; array[i] != NULL; i++) {
        copy[i] = malloc(sizeof(char) * strlen(array[i]) + 1);
        strcpy(copy[i], array[i]);
        k++;
    }
    copy[k] = NULL;
    return copy;
}
