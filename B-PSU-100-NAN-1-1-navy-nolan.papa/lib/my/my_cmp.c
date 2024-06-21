/*
** EPITECH PROJECT, 2023
** project
** File description:
** my_cmp
*/

#include "../../include/header.h"

int my_cmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return 1;
        }
    }
    return 0;
}
