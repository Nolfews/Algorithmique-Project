/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** write a charcter string
*/

#include "../../include/header.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
