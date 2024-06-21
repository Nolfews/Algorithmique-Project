/*
** EPITECH PROJECT, 2023
** my strncat
** File description:
** str n cat
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j;

    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; j < nb; j++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return dest;
}
