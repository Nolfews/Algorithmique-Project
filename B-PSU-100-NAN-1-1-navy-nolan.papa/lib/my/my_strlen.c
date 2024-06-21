/*
** EPITECH PROJECT, 2023
** My PutSTR
** File description:
** this function displays, one-by-one, the characters of a string.
*/

#include "../../include/header.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
