/*
** EPITECH PROJECT, 2024
** my strcmp
** File description:
** my strcmp
*/

#include "header.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return (84);
    for (int i = 0; i < my_strlen(str1); i++) {
        if (str1[i] != str2[i]) {
            return (84);
        }
    }
    return (0);
}
