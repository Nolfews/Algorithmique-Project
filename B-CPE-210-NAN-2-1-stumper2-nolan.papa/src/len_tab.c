/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** len_tab
*/

#include <stdio.h>

int len_tab(char **array)
{
    int i = 0;
    int count = 1;

    while (array[i] != NULL) {
        i++;
        count++;
    }
    return count;
}
