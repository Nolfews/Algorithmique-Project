/*
** EPITECH PROJECT, 2023
** sort
** File description:
** sort
*/

#include "libshell/shell.h"
#include "header.h"

static void inv_swap_elem(s_lst **elem, s_lst_g **tete, s_lst **prec)
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

static int inv_cmpid(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    if (elem->id < elem->next->id) {
        inv_swap_elem(&elem, &tete, &prec);
        swap++;
        return swap;
    }
    return 0;
}

int inv_cmpstr(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    for (int i = 0; elem->name[i] != '\0' &&
        elem->next->name[i] != '\0'; i++) {
        if (elem->name[i] < elem->next->name[i]) {
            inv_swap_elem(&elem, &tete, &prec);
            swap++;
            return swap;
        }
    }
    if (my_strlen(elem->name) > my_strlen(elem->next->name)) {
        inv_swap_elem(&elem, &tete, &prec);
        swap++;
        return swap;
    }
    return 0;
}

int inv_cmptype(s_lst *elem, s_lst_g *tete, char **args, s_lst *prec)
{
    int swap = 0;

    for (int i = 0; elem->type[i] != '\0' &&
        elem->next->type[i] != '\0'; i++) {
        if (elem->type[i] < elem->next->type[i]) {
            inv_swap_elem(&elem, &tete, &prec);
            swap++;
            return swap;
        }
    }
    if (my_strlen(elem->type) > my_strlen(elem->next->type)) {
        inv_swap_elem(&elem, &tete, &prec);
        swap++;
    }
    return swap;
}

static int inv_cmp_struct(s_lst *elem, char **args, s_lst_g *tete, s_lst *prec)
{
    int swap = 0;

    if (elem == NULL || elem->next == NULL)
        return swap;
    if (my_strcmp(args[0], "TYPE") == 0) {
        swap += inv_cmptype(elem, tete, args, prec);
        return swap;
    }
    if (my_strcmp(args[0], "NAME") == 0) {
        swap += inv_cmpstr(elem, tete, args, prec);
        return swap;
    }
    if (my_strcmp(args[0], "ID") == 0) {
        swap += inv_cmpid(elem, tete, args, prec);
        return swap;
    }
    return swap;
}

int inv_bubble_sort(void *data, char **args)
{
    s_lst *elem = ((s_lst_g *)data)->start;
    s_lst_g *tete = ((s_lst_g *)data);
    s_lst *prec = ((s_lst_g *)data)->start;
    int nb_swap = 0;

    while (elem != NULL) {
        if (elem->next == NULL)
            break;
        nb_swap = inv_cmp_struct(elem, args, tete, prec);
        prec = elem;
        elem = elem->next;
    }
    if (nb_swap != 0) {
        inv_bubble_sort(tete, args);
    }
    return 0;
}
