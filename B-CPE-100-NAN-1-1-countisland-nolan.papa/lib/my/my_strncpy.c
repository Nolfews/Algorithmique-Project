/*
** EPITECH PROJECT, 2023
** my strncpy
** File description:
** copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    if (&src <= &dest) {
        for (i = 0; i <= n; i++) {
            dest[i] = src[i];
        }
        dest[i + 1] = '\0';
        return (dest);
    }
    return (dest);
}
