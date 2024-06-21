/*
** EPITECH PROJECT, 2023
** my get nbr
** File description:
** get number
*/

#include "header.h"

int my_str_to_nbr(char const *str)
{
    int nb = 0;

    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == '\0') {
            return (nb);
        }
        if (i == 0) {
            nb = str[i] - 48;
        }
        if (i >= 1) {
            nb = (nb * 10) + str[i] - 48;
        }
    }
    return (nb);
}
