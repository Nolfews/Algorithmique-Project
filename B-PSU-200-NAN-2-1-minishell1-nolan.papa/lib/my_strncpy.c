/*
** EPITECH PROJECT, 2023
** my strncpy
** File description:
** copies n characters from a string into another.
*/

#include "../header.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    if (my_strlen(src) <= my_strlen(dest)) {
        for (i = 0; i <= n; i++) {
            dest[i] = src[i];
        }
        dest[i + 1] = '\0';
        return (dest);
    }
    return (dest);
}
