/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** allow memory
*/

#include <stdlib.h>
#include "../../include/header.h"

char *my_strdup(char const *src)
{
    int lenght_src = my_strlen(src);
    int i;
    char *dest = malloc(sizeof(char) * (lenght_src + 1));

    for (i = 0; i < my_strlen(src); i ++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
