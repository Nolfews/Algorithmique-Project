/*
** EPITECH PROJECT, 2023
** 101pong
** File description:
** d
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double get_velo_vector(double *coord_0, double *coord_1)
{
    double vector[4];

    vector[0] = coord_1[0] - coord_0[0];
    vector[1] = coord_1[1] - coord_0[1];
    vector[2] = coord_1[2] - coord_0[2];

    printf("The velocity vector of the ball is:\n(%.2lf, %.2lf, %.2lf)\n", vector[0], vector[1], vector[2]);
}


int main(int ac, char **av)
{
    double coord_0[4];
    double coord_1[4];
    double moves = 0;
    int contact = 0;

    coord_0[0] = strtod(av[1], NULL);
    coord_0[1] = strtod(av[2], NULL);
    coord_0[2] = strtod(av[3], NULL);
    coord_1[0] = strtod(av[4], NULL);
    coord_1[1] = strtod(av[5], NULL);
    coord_1[2] = strtod(av[6], NULL);
    moves = strtod(av[7], NULL);

    get_velo_vector(coord_0, coord_1);

}