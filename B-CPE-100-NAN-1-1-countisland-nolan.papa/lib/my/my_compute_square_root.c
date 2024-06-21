/*
** EPITECH PROJECT, 2023
** my compute square root
** File description:
** returns the square root (if it is a whole number)
** of the number given as argument.
*/

int my_compute_square_root(int nb)
{
    int i;
    int compt = 0;
    int result = 1;

    if (nb == 0) {
        return (0);
    } else if ( nb == 1) {
        return (1);
    }
    for (i = 1; i <= nb; i = i + 2) {
        result = i;
        nb = nb - i;
        compt++;
    }
    if (nb == 0) {
        return (compt);
    } else {
        return (0);
    }
}
