/*
** EPITECH PROJECT, 2024
** error handler
** File description:
** error handler
*/

#include "../header.h"

static int error_str_unsetenv_two(char **arg, int j)
{
    for (int i = 0; arg[j][i] != '\0'; i++) {
        if (arg[j][i] < '0' || arg[j][i] > '9' && arg[j][i] < 'A' ||
            arg[j][i] > 'Z' && arg[j][i] < 'a' || arg[j][i] > 'z') {
            return 84;
        }
    }
    return 0;
}

int error_str_setenv(char **arg, int i)
{
    if (i == 1) {
        return 0;
    }
    for (int i = 0; arg[1][i] != '\0'; i++) {
        if (arg[1][i] < '0' || arg[1][i] > '9' && arg[1][i] < 'A' ||
            arg[1][i] > 'Z' && arg[1][i] < 'a' || arg[1][i] > 'z') {
                my_putstr(arg[0]);
                my_putstr(": Variable name must contain ");
                my_putstr("alphanumeric characters.\n");
            return 84;
        }
    }
    return 0;
}

int error_str_unsetenv(char **arg, int i)
{
    if (i == 1) {
        return 0;
    }
    for (int j = 1; arg[j] != NULL; j++) {
        if (error_str_unsetenv_two(arg, j) == 84)
            return 84;
    }
    return 0;
}

int error_setenv(char **arg, env_t *env, int i)
{
    if (arg[1] == NULL && i == 1) {
        my_env(env);
        return 2;
    }
    if (arg[1] != NULL) {
        if (error_str_setenv(arg, i) == 84) {
            return 84;
        }
    } else {
        return 84;
    }
    if (arg[2] != NULL && arg[3] != NULL) {
        return 84;
    }
    return 0;
}

int error_unsetenv(char **arg)
{
    if (arg[1] == NULL) {
        return 84;
    }
    if (error_str_unsetenv(arg, 0) == 84) {
        return 84;
    }
    return 0;
}
