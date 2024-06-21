/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** copies a string into another.
*/

char *my_strcpy(char *dest, char const *src)
{
    int length_src = my_strlen(src);
    int i;

    if (&src <= &dest) {
        for (i = 0; i <= length_src; i++) {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
    return (dest);
}
