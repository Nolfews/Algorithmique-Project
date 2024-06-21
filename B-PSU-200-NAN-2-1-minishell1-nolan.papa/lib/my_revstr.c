/*
** EPITECH PROJECT, 2023
** my revstr
** File description:
** reverses a string.
*/

#include "../header.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    char nb;

    for (int i = 0; i < length / 2; i++) {
        nb = str[i];
        str[i] = str[length - i];
        str[length - i] = nb;
    }
    return (str);
}
