/*
** EPITECH PROJECT, 2023
** my putchar
** File description:
** putchar
*/

#include "../header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
