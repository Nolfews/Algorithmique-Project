/*
** EPITECH PROJECT, 2023
** disp
** File description:
** disp
*/

#include "libshell/shell.h"
#include "header.h"

int disp(void *data, char **args)
{
    s_lst *tempo = ((s_lst_g *)data)->start;

    if (args[0] != NULL) {
        return (84);
    }
    while (tempo != NULL) {
        my_putstr(tempo->type);
        my_putstr(" n°");
        my_put_nbr(tempo->id);
        my_putstr(" - \"");
        my_putstr(tempo->name);
        my_putstr("\"\n");
        tempo = tempo->next;
    }
    return (0);
}
