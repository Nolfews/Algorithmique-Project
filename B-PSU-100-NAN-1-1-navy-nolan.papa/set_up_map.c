/*
** EPITECH PROJECT, 2024
** set up map
** File description:
** set up map
*/

#include "include/header.h"

static int check_boat(char **map)
{
    int nb_2 = 0;
    int nb_3 = 0;
    int nb_4 = 0;
    int nb_5 = 0;

    for (int i = 3; map[i] != NULL; i++) {
        for (int j = 2; map[i][j] != '\0'; j++) {
            nb_2 = check_boat2(map, i, j, nb_2);
            nb_3 = check_boat3(map, i, j, nb_3);
            nb_4 = check_boat4(map, i, j, nb_4);
            nb_5 = check_boat5(map, i, j, nb_5);
        }
    }
    if (nb_2 != 2 || nb_3 != 3 || nb_4 != 4 || nb_5 != 5)
        return 84;
    return 0;
}

static int letter_to_number(char c)
{
    int nb = 0;

    for (int i = 1; i <= 8; i++) {
        if (((c) - (64 + i)) == 0) {
            nb = i * 2;
            return (nb);
        }
    }
    return (0);
}

static void stock_co_boat(co_p *ligne_co, char *buf)
{
    ligne_co->len_boat = buf[0] - 48;
    ligne_co->start_x = letter_to_number(buf[2]);
    ligne_co->start_y = buf[3] - 46;
    ligne_co->end_x = letter_to_number(buf[5]);
    ligne_co->end_y = buf[6] - 46;
}

char **create_map_2d(char *filpath)
{
    char **map = malloc(sizeof(char *) * 12);
    int fd = open(filpath, O_RDONLY);
    char *buf = malloc(sizeof(char) * 19);
    int j = 0;

    map[11] = NULL;
    for (int i = 0; i < 11; i++) {
        map[i] = malloc(sizeof(char) * 19);
    }
    read(fd, buf, 9);
    buf[10] = '\0';
    for (int i = 0; i < 11; i++) {
        for (j = 0; buf[j] != '\0'; j++) {
            map[i][j] = buf[j];
        }
        map[i][j + 1] = '\0';
        read(fd, buf, 18);
        buf[18] = '\0';
    }
    return (map);
}

static int update_y(int i)
{
    if (i > 1)
        return (i - 1);
    return (0);
}

static int update_x(int i, int x)
{
    if (i > 1)
        return (x + 2);
    return (0);
}

char **update_map(char **map, co_p *lig_co)
{
    int x = 0;
    int y = 0;

    for (int i = 1; i <= lig_co->len_boat; i++) {
        if (lig_co->start_x == lig_co->end_x) {
            y = update_y(i);
            map[lig_co->start_y + y][lig_co->start_x] = lig_co->len_boat + 48;
        }
        if (lig_co->start_y == lig_co->end_y) {
            x = update_x(i, x);
            map[lig_co->start_y][lig_co->start_x + x] = lig_co->len_boat + 48;
        }
    }
    return (map);
}

char **set_up_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buf = malloc(sizeof(char) * 9);
    co_p *ligne_co = malloc(sizeof(co_p));
    char **map = create_map_2d("map/map_player1.txt");

    read(fd, buf, 8);
    buf[8] = '\0';
    for (int i = 0; i <= 3; i++) {
        stock_co_boat(ligne_co, buf);
        map = update_map(map, ligne_co);
        read(fd, buf, 8);
    }
    close(fd);
    free(buf);
    if (check_boat(map) == 84)
        return (NULL);
    return (map);
}
