/*
** EPITECH PROJECT, 2023
** sort
** File description:
** sort
*/

#include "libshell/shell.h"
#include "header.h"

static int error_sort(void *data, char **args)
{
    s_lst_g *lst_g = ((s_lst_g *)data);

    if (lst_g == NULL)
        return 84;
    if (args[0] == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "TYPE") == 84 &&
            my_strcmp(args[i], "ID") == 84 &&
            my_strcmp(args[i], "NAME") == 84 &&
            my_strcmp(args[i], "-r") == 84) {
                return 84;
            }
        if (my_strcmp(args[i], "-r") == 0 && my_strcmp(args[i + 1], "-r") == 0)
            return 84;
    }
    if (my_strcmp(args[0], "-r") == 0)
        return 84;
    return 0;
}

static void swap_elem(s_lst **elem, s_lst_g **tete, s_lst **prec)
{
    s_lst *proch = (*elem)->next;
    s_lst *current = (*elem);

    if (current == (*tete)->start) {
        current->next = (*elem)->next->next;
        proch->next = current;
        (*tete)->start = proch;
        return;
    }
    current->next = (*elem)->next->next;
    proch->next = current;
    (*prec)->next = proch;
}

static int cmpid(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    if (elem->id > elem->next->id) {
        swap_elem(&elem, &tete, &prec);
        swap++;
    }
    return swap;
}

int cmpstr(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    for (int i = 0; elem->name[i] != '\0' &&
        elem->next->name[i] != '\0'; i++) {
        if (elem->name[i] > elem->next->name[i]) {
            swap_elem(&elem, &tete, &prec);
            swap++;
            return swap;
        }
    }
    if (my_strlen(elem->name) < my_strlen(elem->next->name)) {
        swap_elem(&elem, &tete, &prec);
        swap++;
    }
    return swap;
}

int cmptype(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    for (int i = 0; elem->type[i] != '\0' &&
        elem->next->type[i] != '\0'; i++) {
        if (elem->type[i] > elem->next->type[i]) {
            swap_elem(&elem, &tete, &prec);
            swap++;
            return swap;
        }
    }
    if (my_strlen(elem->type) < my_strlen(elem->next->type)) {
        swap_elem(&elem, &tete, &prec);
        swap++;
    }
    return swap;
}

static int cmp_struct(s_lst *elem, char **args, s_lst_g *tete, s_lst *prec)
{
    int swap = 0;

    if (elem == NULL || elem->next == NULL)
        return swap;
    if (my_strcmp(args[0], "TYPE") == 0) {
        swap += cmptype(elem, tete, args, prec);
        return swap;
    }
    if (my_strcmp(args[0], "NAME") == 0) {
        swap += cmpstr(elem, tete, args, prec);
        return swap;
    }
    if (my_strcmp(args[0], "ID") == 0) {
        swap += cmpid(elem, tete, args, prec);
        return swap;
    }
    return swap;
}

static int bubble_sort(void *data, char **args)
{
    s_lst *elem = ((s_lst_g *)data)->start;
    s_lst_g *tete = ((s_lst_g *)data);
    s_lst *prec = ((s_lst_g *)data)->start;
    int nb_swap = 0;

    while (elem != NULL) {
        if (elem->next == NULL)
            break;
        nb_swap = cmp_struct(elem, args, tete, prec);
        prec = elem;
        elem = elem->next;
    }
    if (nb_swap != 0) {
        bubble_sort(tete, args);
    }
    return 0;
}

int sort(void *data, char **args)
{
    s_lst_g *tete = ((s_lst_g *)data);

    if (error_sort(data, args) == 84)
        return 84;
    if (args[1] == NULL) {
        for (int i = 0; i < tete->index_max; i++) {
            bubble_sort(data, args);
        }
        return 0;
    }
    if (my_strcmp(args[1], "-r") == 0) {
        my_putstr("test1\n");
        for (int i = 0; i < tete->index_max; i++) {
            my_putstr("test2\n");
            inv_bubble_sort(data, args);
        }
        return 0;
    }
}
