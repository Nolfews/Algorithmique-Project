/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** counts and returns the number of characters
*/

#include "../hashtable.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
