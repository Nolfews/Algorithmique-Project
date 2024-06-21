/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "libshell/shell.h"
#include "header.h"

int main(int ac, char **av)
{
    s_lst_g *lst_g = malloc(sizeof(s_lst_g));
    s_lst *objet = NULL;

    lst_g->start = objet;
    lst_g->index_max = 0;
    return (workshop_shell(lst_g));
}
