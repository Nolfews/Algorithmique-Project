/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** print array
*/

#include "../includes/my.h"
#include <stdio.h>

void print_array(char **arg)
{
    while (*arg) {
        printf("%s\n", *arg);
        arg++;
    }
}
