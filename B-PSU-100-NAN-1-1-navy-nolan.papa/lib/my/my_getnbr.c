/*
** EPITECH PROJECT, 2023
** project
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int my_isneg = 1;
    int i = 0;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            my_isneg = my_isneg * -1;
        i = i + 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        } else
            return (nb * my_isneg);
        i = i + 1;
    }
    return (nb * my_isneg);
}
