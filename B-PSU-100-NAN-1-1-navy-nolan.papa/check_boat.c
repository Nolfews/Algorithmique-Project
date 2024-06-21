/*
** EPITECH PROJECT, 2024
** check boat
** File description:
** check boat
*/

#include "include/header.h"

int check_boat2(char **map, int i, int j, int nb_2)
{
    if (map[i][j] == '2')
        nb_2++;
    return (nb_2);
}

int check_boat3(char **map, int i, int j, int nb_3)
{
    if (map[i][j] == '3')
        nb_3++;
    return (nb_3);
}

int check_boat4(char **map, int i, int j, int nb_4)
{
    if (map[i][j] == '4')
        nb_4++;
    return (nb_4);
}

int check_boat5(char **map, int i, int j, int nb_5)
{
    if (map[i][j] == '5')
        nb_5++;
    return (nb_5);
}
