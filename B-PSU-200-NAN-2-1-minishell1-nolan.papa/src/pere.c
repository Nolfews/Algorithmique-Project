/*
** EPITECH PROJECT, 2024
** pere
** File description:
** pere
*/

#include "../header.h"

static char *check_env(char **arg, env_t *env)
{
    char *str;
    char **path;

    for (int i = 0; env->env[i] != NULL; i++) {
        if (env->env[i][0] == 'P' && env->env[i][1] == 'A')
            str = my_strcpy(env->env[i]);
    }
    path = str_to_array(str, "=");
    path = str_to_array(path[1], ":");
    for (int i = 0; path[i] != NULL; i++) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], arg[0]);
        if (access(path[i], X_OK) == 0)
            return path[i];
    }
    return NULL;
}

static int check_line_slave(char **arg, env_t *env)
{
    if (my_strcmp(arg[0], "unsetenv") == 0) {
        if (error_unsetenv(arg) == 0) {
            my_unsetenv(arg, env);
            return 1;
        }
        return 1;
    }
    return 0;
}

static int check_set_env(char **arg, env_t *env)
{
    if (my_strcmp(arg[0], "setenv") == 0) {
        if (error_setenv(arg, env, 0) == 0) {
            my_setenv(arg[1], arg[2], env);
            return 1;
        }
        return 1;
    }
    return 0;
}

int check_line(char **arg, env_t *env)
{
    int nb = 0;

    if (arg[0] == NULL)
        return 1;
    if (my_strcmp(arg[0], "exit") == 0)
        my_exit(arg, env->status);
    if (my_strcmp(arg[0], "env") == 0) {
        if (arg[1] == NULL) {
            my_env(env);
            return 1;
        }
    }
    if (check_set_env(arg, env) == 1) {
        return 1;
    }
    nb = check_line_slave(arg, env);
    return nb;
}

void line_call(env_t *env, char *line)
{
    int bool;
    size_t len = 0;
    pid_t pid;
    char **arg;

    arg = str_to_array(line, " \t\n");
    if (check_line(arg, env) == 1) {
        return;
    }
    env->path = check_env(arg, env);
    pid = fork();
    action_fils(env, arg, pid);
}

int action_pere(env_t *env)
{
    char *line = NULL;
    size_t len = 0;
    char *new_env;
    char *path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";

    while (1) {
        if (env->env[0] == NULL) {
        exit(0);
        }
        if (isatty(0) != 0) {
            my_putstr("$> ");
        }
        if (getline(&line, &len, stdin) == -1)
            return env->status;
        line_call(env, line);
    }
}
