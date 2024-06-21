/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** str to array
*/

#include "../includes/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char **str_to_array(char *argv, char *separateur)
{
    char **array;
    char *strtoken;
    int i = 0;
    int nb_arg = 0;

    for (int k = 0; argv[k] != '\0'; k++) {
        if (argv[k] == '\n')
            nb_arg++;
    }
    array = malloc(sizeof(char *) * nb_arg + 1);
    strtoken = strtok(argv, separateur);
    while (strtoken != NULL) {
        array[i] = malloc(sizeof(char) * strlen(strtoken) + 1);
        strcpy(array[i], strtoken);
        array[i][strlen(strtoken)] = '\0';
        i++;
        strtoken = strtok(NULL, separateur);
    }
    array[i] = NULL;
    return array;
}
