/*
** EPITECH PROJECT, 2023
** header.h
** File description:
** header.h
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

typedef struct lst {
    int id;
    char *type;
    char *name;
    struct lst *next;
} s_lst;

typedef struct lst_g {
    int index_max;
    s_lst *start;
} s_lst_g;

char *my_strcpy(char const *src);
int my_strlen(char const *str);
void my_put_nbr(int nb);
void my_putstr(char const *str);
void my_putchar(char c);
int my_str_to_nbr(char const *str);
int my_strcmp(char *str1, char *str2);
int cmpstr(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec);
int cmptype(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec);
int inv_bubble_sort(void *data, char **args);

#endif /* HEADER_H_ */
