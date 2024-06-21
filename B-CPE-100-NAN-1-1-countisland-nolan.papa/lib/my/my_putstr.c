/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

void my_putchar2(char c)
{
    write(1, &c, 1);
}

int    my_putstr(char const *str)
{
    int i;

    for (i = 0; *(str + i) != '\0'; i++) {
        my_putchar2(*(str + i));
    }
}
