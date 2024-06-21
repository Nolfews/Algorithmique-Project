/*
** EPITECH PROJECT, 2023
** add
** File description:
** add
*/

#include "libshell/shell.h"
#include "header.h"

int error_add(char **args)
{
    int j = 0;

    if (args[0] == NULL) {
        return (84);
    }
    for (j = 0; args[j] != NULL; j++);
    if (j % 2 == 1) {
            return (84);
        }
    for (int i = 0; args[i] != NULL; i += 2) {
        if (my_strcmp(args[i], "ACTUATOR") == 0 ||
            my_strcmp(args[i], "DEVICE") == 0 ||
            my_strcmp(args[i], "PROCESSOR") == 0 ||
            my_strcmp(args[i], "SENSOR") == 0 ||
            my_strcmp(args[i], "WIRE") == 0) {
        } else {
            return (84);
        }
    }
    return (0);
}

int add_item(void *data, char *type, char *name)
{
    s_lst *node = malloc(sizeof(s_lst));

    node->id = ((s_lst_g *)data)->index_max;
    node->type = my_strcpy(type);
    node->name = my_strcpy(name);
    node->next = ((s_lst_g *)data)->start;
    ((s_lst_g *)data)->index_max++;
    ((s_lst_g *)data)->start = node;
    my_putstr(node->type);
    my_putstr(" n°");
    my_put_nbr(node->id);
    my_putstr(" - \"");
    my_putstr(node->name);
    my_putstr("\" added.\n");
    return (0);
}

int add(void *data, char **args)
{
    int nb = 0;

    if (error_add(args) == 84) {
        return (84);
    }
    for (int i = 0; args[i] != NULL; i++) {
        nb++;
    }
    if (nb % 2 != 0) {
        return (84);
    }
    for (int i = 0; args[i] != NULL; i += 2) {
        add_item(data, args[i], args[i + 1]);
    }
    return (0);
}
