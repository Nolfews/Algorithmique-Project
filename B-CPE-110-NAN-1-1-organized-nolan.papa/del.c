/*
** EPITECH PROJECT, 2023
** del
** File description:
** del
*/

#include "libshell/shell.h"
#include "header.h"

int error_del(void *data, char **args)
{
    s_lst_g *lst_g = ((s_lst_g *)data);

    if (args[0] == NULL) {
        return (84);
    }
    for (int i = 0; args[i] != NULL; i++) {
        if (my_str_to_nbr(args[i]) > lst_g->index_max) {
            return (84);
        }
    }
    return (0);
}

void aff_del_msg(s_lst *tempo)
{
    my_putstr(tempo->next->type);
    my_putstr(" n°");
    my_put_nbr(tempo->next->id);
    my_putstr(" - \"");
    my_putstr(tempo->next->name);
    my_putstr("\" deleted.\n");
}

void aff_del_first_msg(s_lst *tempo)
{
    my_putstr(tempo->type);
    my_putstr(" n°");
    my_put_nbr(tempo->id);
    my_putstr(" - \"");
    my_putstr(tempo->name);
    my_putstr("\" deleted.\n");
}

int del_one(void *data, int id)
{
    s_lst *tempo = ((s_lst_g *)data)->start;

    if (tempo == NULL) {
        return (84);
    }
    if (tempo->id == id) {
        aff_del_first_msg(tempo);
        ((s_lst_g *)data)->start = ((s_lst_g *)data)->start->next;
        return (0);
    }
    while (tempo->next != NULL) {
        if (tempo->next->id == id) {
            aff_del_msg(tempo);
            tempo->next = tempo->next->next;
        } else {
            tempo = tempo->next;
        }
    }
    return (0);
}

int del(void *data, char **args)
{
    if (error_del(data, args) == 84) {
        return (84);
    }
    for (int i = 0; args[i] != NULL; i++) {
        del_one(data, my_str_to_nbr(args[i]));
    }
    return (0);
}
