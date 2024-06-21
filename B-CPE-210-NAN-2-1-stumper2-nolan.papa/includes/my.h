/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** include file
*/

#ifndef MY_H
    #define MY_H

void my_putchar(char c);
void my_putnbr(int nb);
void case_error(int argc, char **argv);
char **str_to_array(char *argv, char *separateur);
char **parsing_file(char *filepath);
void print_array(char **str);
char **my_arraycpy(char **array);
int len_tab(char **array);
char **cells_evolution(char *filepath, int nb_iter);
int check_isolation(int i, int j, char **array);
int check_suffocation(int i, int j, char **array);
int check_if_three_neighbor(int i, int j, char **array);
void get_nb_neighbor(int i, int j, char **array, int *nb_neighbor);
void free_array(char **array);

#endif
