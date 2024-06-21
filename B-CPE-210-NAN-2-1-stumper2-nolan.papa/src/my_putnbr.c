/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** my_put_nbr function
*/

#include "../includes/my.h"
#include <unistd.h>

void my_putnbr(int nb)
{
    if (nb > 2147483647 || nb <= -2147483648) {
        write(2, "Error: number is too big", 24);
        my_putchar('\n');
        return;
    } else {
        if (nb < 0) {
            my_putchar('-');
            nb *= -1;
        }
        if (nb >= 10) {
            my_putnbr(nb / 10);
        }
        my_putchar((nb % 10) + '0');
    }
}
