/*
** EPITECH PROJECT, 2024
** env
** File description:
** env
*/

#include "../header.h"

void my_env(env_t *env)
{
    printlist(env->lst_env);
}

void my_setenv(char *name, char *value, env_t *env)
{
    char **tempo;
    c_env_t *env_tempo = env->lst_env;
    char *str_tempo;

    for (int i = 0; env_tempo != NULL; i++) {
        tempo = str_to_array(env_tempo->data, "=");
        if (my_strcmp(name, tempo[0]) == 0) {
            env_tempo->data = my_strcpy(name);
            env_tempo->data = my_strcat(env_tempo->data, "=");
            env_tempo->data = my_strcat(env_tempo->data, value);
            insert(env->lst_env, env_tempo);
            return;
        }
        env_tempo = env_tempo->next;
    }
    str_tempo = my_strcpy(name);
    str_tempo = my_strcat(str_tempo, "=");
    str_tempo = my_strcat(str_tempo, value);
    append(&env->lst_env, str_tempo);
}

static void unsetenv_two(env_t *env, char **name, int i)
{
    char **tempo;
    c_env_t *env_tempo = env->lst_env;

    for (int j = 0; env_tempo != NULL; j++) {
        tempo = str_to_array(env_tempo->data, "=");
        if (my_strcmp(name[i], tempo[0]) == 0) {
            env_tempo->data = NULL;
            insert(env->lst_env, env_tempo);
            return;
        }
        env_tempo = env_tempo->next;
    }
}

void my_unsetenv(char **name, env_t *env)
{
    for (int i = 1; name[i] != NULL; i++) {
        printf("%s\n", name[i]);
        unsetenv_two(env, name, i);
    }
}
