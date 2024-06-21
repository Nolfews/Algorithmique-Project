/*
** EPITECH PROJECT, 2023
** my compute power rec
** File description:
** that returns the first argument raised to the power p.
*/

int my_compute_power_rec(int nb, int p)
{
    if ( p < 0) {
        return (0);
    } else if ( p == 0) {
        return (1);
    }
    return (my_compute_power_rec(nb, p - 1) * nb);
}
