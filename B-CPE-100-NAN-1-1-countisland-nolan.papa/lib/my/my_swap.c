/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap the content of two integers
*/

void    my_swap(int *a, int *b)
{
    int nb;

    nb = *a;
    *a = *b;
    *b = nb;
}
