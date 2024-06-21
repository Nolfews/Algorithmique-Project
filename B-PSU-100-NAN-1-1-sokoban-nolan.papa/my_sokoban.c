/*
** EPITECH PROJECT, 2023
** my sokoban
** File description:
** my popup
*/

#include "header.h"

char *read_file(char *filepath, char *map)
{
    struct stat info;
    int fo = open(filepath, O_RDONLY);
    int fs = stat(filepath, &info);
    char *buffer = malloc(sizeof(char) * info.st_size + 5);
    int i;

    read(fo, buffer, info.st_size);
    buffer[info.st_size] = '\0';
    map = malloc(sizeof(char) * info.st_size + 5);
    for (i = 0; i < info.st_size; i++) {
        map[i] = buffer[i];
    }
    map[info.st_size] = '\0';
    check_error_in_file(buffer);
    free(buffer);
    return (map);
}

static void condition_comp(char **map, char **map_copy, int j, int i)
{
    if (map[j][i] == ' ' && map_copy[j][i] == 'O') {
        map[j][i] = 'O';
    }
}

void comp_map(char **map, char **map_copy)
{
    for (int j = 0; map[j] != NULL; j++) {
        for (int i = 0; map[j][i] != '\0'; i++) {
            condition_comp(map, map_copy, j , i);
        }
    }
}

void aff_map_in_game(char **map_2d, char **map_copy)
{
    int indice = 0;

    clear();
    for (int j = 0; map_2d[j] != NULL; j++) {
        printw("%s", map_2d[j]);
        printw("\n");
    }
    condi_end(map_2d, map_copy);
}

static int nb_ligne_map(char *map)
{
    int nb = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            nb++;
        }
    }
    return (nb + 1);
}

static int len_ligne_map(char *map)
{
    int nb = 0;

    for (int i = 0; map[i] != '\n'; i++) {
        nb++;
    }
    return (nb + 1);
}

static char **map_2d(char *filepath)
{
    char **map_2d;
    char *map = read_file(filepath, map);
    int nb_ligne = nb_ligne_map(map);
    int indice = 0;
    int i = 0;

    map_2d = malloc(sizeof(char *) * nb_ligne);
    for (int i = 0; i < nb_ligne; i++) {
        map_2d[i] = malloc(sizeof(char) * len_ligne_map(map));
    }
    map_2d[nb_ligne - 1] = NULL;
    for (int j = 0; map_2d[j] != NULL; j++) {
        for (i = 0; map[indice + i] != '\n'; i++)
            map_2d[j][i] = map[indice + i];
        indice += i + 1;
        map_2d[j][i] = '\0';
    }
    free(map);
    return (map_2d);
}

static void set_up_game(void)
{
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    move(0, 0);
    signal(SIGWINCH, NULL);
}

void boucle_game(char **map, char **map_copy, char **av, s_co *co)
{
    int input;

    while (1) {
        aff_map_in_game(map, map_copy);
        input = getch();
        if (input == ' ') {
            map = map_2d(av[1]);
            find_player(co, map);
        } else {
            check_key(co, map, input);
            comp_map(map, map_copy);
        }
        if (input == 27) {
            break;
        }
        refresh();
    }
}

void game_loop(int ac, char **av)
{
    char **map = map_2d(av[1]);
    s_co co;
    char **map_copy = map_2d(av[1]);

    set_up_game();
    find_player(&co, map);
    boucle_game(map, map_copy, av, &co);
    endwin();
}
