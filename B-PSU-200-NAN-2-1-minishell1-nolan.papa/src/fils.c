/*
** EPITECH PROJECT, 2024
** fils
** File description:
** fils
*/

#include "../header.h"
static void print_error_command(char *input)
{
    if (errno == 2) {
        my_putstr(input);
        my_putstr(": Command not found.\n");
    }
    if (errno == 13) {
        my_putstr(input);
        my_putstr(": Exec format error. Wrong Architecture.\n");
    }
    exit(EXIT_FAILURE);
}

void print_status(env_t *env, char *filepath, char *input)
{
    if (env->status == 11) {
        my_putstr("Segmentation fault\n");
        return;
    }
    if (env->status == 139) {
        my_putstr("Segmentation fault (core dumped)\n");
        return;
    }
    if (env->status == 256) {
        env->status = 1;
    }
}

void print_error_call(int status, char *fp, char *input)
{
    struct stat *s_stat;

    if (stat(fp, s_stat) == 0) {
        if ((s_stat->st_mode & __S_IFMT) == __S_IFDIR) {
            my_putstr(input);
            my_putstr(": Permission denied.\n");
            exit(EXIT_FAILURE);
        }
    }
    if (access(fp, X_OK) == -1) {
        print_error_command(input);
    }
}

void update_arg(char **arg)
{
    for (int i = 0; arg[i] != NULL; i++) {
        if (arg[i][my_strlen(arg[i]) - 1] == '\n') {
            arg[i][my_strlen(arg[i]) - 1] = '\0';
        }
    }
}

void action_fils(env_t *env, char **arg, pid_t pid)
{
    char *filepath = arg[0];
    char *input = arg[0];

    if (env->path != NULL)
        filepath = env->path;
    if (pid == 0) {
        update_arg(arg);
        print_error_call(env->status, filepath, input);
        execve(filepath, arg, env->env);
    } else {
        waitpid(pid, &env->status, 0);
        print_status(env, filepath, input);
    }
}
