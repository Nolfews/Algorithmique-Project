/*
** EPITECH PROJECT, 2023
** my strcat
** File description:
** str cat
*/

#include "../header.h"

char *my_strcat(char *dest, char *src)
{
    int len_src = my_strlen(src);
    int len_dest = my_strlen(dest);
    char *new_str = malloc(sizeof(char) * (len_src + len_dest));
    int i = 0;
    int j = 0;

    if (src == NULL)
        return dest;
    for (i = 0; dest[i] != '\0'; i++) {
        new_str[i] = dest[i];
    }
    for (j = 0; src[j] != '\0'; j++) {
        new_str[i + j] = src[j];
    }
    new_str[i + j] = '\0';
    return (new_str);
}
