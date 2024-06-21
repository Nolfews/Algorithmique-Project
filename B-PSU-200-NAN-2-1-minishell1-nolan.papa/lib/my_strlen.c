/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** counts and returns the number of characters
*/

#include "../header.h"

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
