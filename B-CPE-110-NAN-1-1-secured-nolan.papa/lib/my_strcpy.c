/*
** EPITECH PROJECT, 2023
** my strcpy
** File description:
** copies a string into another.
*/

#include "../hashtable.h"
#include <stdlib.h>

char *my_strcpy(char const *src)
{
    int length_src = my_strlen(src);
    int i;
    char *dest = malloc(sizeof(char) * length_src + 1);

    for (i = 0; i <= length_src; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
