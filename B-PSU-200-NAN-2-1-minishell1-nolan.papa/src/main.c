/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../header.h"

static void error_handler(int argc, char **argv)
{
    if (argc != 1)
        exit(84);
}

int nb_ligne(char *str)
{
    int nb_arg = 0;

    for (int k = 0; str[k] != '\0'; k++) {
        if (str[k] == ' ')
            nb_arg++;
        if (str[k] == '\n')
            nb_arg++;
        if (str[k] == '\t')
            nb_arg++;
        if (str[k] == ':')
            nb_arg++;
    }
    return nb_arg;
}

static int get_nb_arg(char *line, char *separator)
{
    char *tmp = my_strcpy(line);
    int nb_arg = 0;

    tmp = strtok(tmp, separator);
    while (tmp != NULL) {
        nb_arg++;
        tmp = strtok(NULL, separator);
    }
    return (nb_arg);
}

char **str_to_array(char *argv, char *separateur)
{
    char **array;
    char *strtoken = my_strcpy(argv);
    int nb_arg = get_nb_arg(argv, separateur);
    int i = 0;

    array = malloc(sizeof(char *) * (nb_arg + 1));
    array[nb_arg] = NULL;
    strtoken = strtok(strtoken, separateur);
    while (strtoken != NULL) {
        array[i] = malloc(sizeof(char) * (my_strlen(strtoken) + 1));
        array[i] = my_strcpy(strtoken);
        i++;
        strtoken = strtok(NULL, separateur);
    }
    return array;
}

void print_arg(char **arg)
{
    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
    }
}

int main(int argc, char **argv, char **env)
{
    env_t *my_env = malloc(sizeof(env_t));
    char **new_env;
    char *path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";

    error_handler(argc, argv);
    if (env[0] == NULL) {
        exit(84);
    }
    my_env->env = my_arraycpy(env);
    my_env->lst_env = create_list(my_env->env);
    my_env->status = 0;
    return action_pere(my_env);
}
