/*
** EPITECH PROJECT, 2023
** my is prime
** File description:
** returns 1 if number is prime.
*/

int my_is_prime(int nb)
{
    int i;
    int cont = 0;

    if (nb == 0 || nb == 1) {
        return 0;
    }
    for (i = 1; i <= nb; i++) {
        if (nb % i == 0) {
            cont++;
        }
    }
    if (cont == 2) {
        return 1;
    } else {
        return 0;
    }
}
