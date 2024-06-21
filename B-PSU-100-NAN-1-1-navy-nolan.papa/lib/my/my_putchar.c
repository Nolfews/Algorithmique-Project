/*
** EPITECH PROJECT, 2023
** My putchar
** File description:
** puts a char
*/
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}
