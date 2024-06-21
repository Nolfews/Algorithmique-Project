/*
** EPITECH PROJECT, 2024
** header
** File description:
** header
*/

#ifndef HEADER
    #define HEADER
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <sys/types.h>
    #include <signal.h>
    #include <sys/wait.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <errno.h>
    #include <string.h>

typedef struct c_env_s {
    char *data;
    struct c_env_s *next;
} c_env_t;

typedef struct env_s {
    struct c_env_s *lst_env;
    char **env;
    char *path;
    int status;
} env_t;

char **my_arraycpy(char **array);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char *str1, char *str2);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);

int action_pere(env_t *env);
void action_fils(env_t *env, char **arg, pid_t pid);
char **str_to_array(char *argv, char *separateur);
void my_exit(char **arg, int status);
void my_env(env_t *env);
int check_line(char **arg, env_t *env);
void print_arg(char **arg);
void update_arg(char **arg);
void my_setenv(char *name, char *value, env_t *env);
void error_line(char **arg);
int error_str_setenv(char **arg, int i);
int error_setenv(char **arg, env_t *env, int i);
int error_unsetenv(char **arg);
void my_unsetenv(char **name, env_t *env);
c_env_t *create_list(char **str);
void printlist(c_env_t *head);
void append(c_env_t **head, char *data);
c_env_t *insert(c_env_t *head, c_env_t *node);

#endif /* HEADER */
