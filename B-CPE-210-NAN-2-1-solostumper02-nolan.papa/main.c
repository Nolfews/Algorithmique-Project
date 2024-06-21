q/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < '0' || av[1][i] > '9')
            return (84);
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < '0' || av[2][i] > '9')
            return (84);
    }
    if (atoi(av[1]) > atoi(av[2]))
        return (84);
}

int main(int ac, char **av)
{
    if (error(ac, av) == 84) {
        return (84);
    }
    for (int i = atoi(av[1]); i <= atoi(av[2]); i++) {
        if (i % 2 == 0 && i % 9 == 0)
            printf("FozzBazz\n");
        if (i % 9 == 0 && i % 2 != 0)
            printf("Bazz\n");
        if (i % 2 == 0 && i % 9 != 0)
            printf("Fozz\n");
        if (i % 2 != 0 && i % 9 != 0)
            printf("%i\n", i);
    }
    return (0);
}
