/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** This function displays the number given as a parameter.
*/

#include "../../include/header.h"

int my_putnbr(int nb)
{
    unsigned int n = nb;

    if (nb < 0) {
        my_putchar('-');
        n = 0 - nb;
    }
    if (n > 9) {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    } else {
        my_putchar(n + '0');
    }
}
