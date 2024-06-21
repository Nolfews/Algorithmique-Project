/*
** EPITECH PROJECT, 2023
** my putchar
** File description:
** putchar
*/

#include "../hashtable.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
