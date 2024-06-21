/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

#include "../hashtable.h"

void my_putstr(char const *str)
{
    int i;

    write(1, str, my_strlen(str));
}
