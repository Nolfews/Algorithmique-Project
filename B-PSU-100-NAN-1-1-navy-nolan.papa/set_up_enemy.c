/*
** EPITECH PROJECT, 2024
** set up enemy
** File description:
** set up enemy
*/

#include "include/header.h"

char **create_map_enemy_2d(char *filpath)
{
    char **map = malloc(sizeof(char *) * 12);
    int fd = open(filpath, O_RDONLY);
    char *buf = malloc(sizeof(char) * 19);
    int j = 0;

    map[11] = NULL;
    for (int i = 0; i < 11; i++) {
        map[i] = malloc(sizeof(char) * 19);
    }
    read(fd, buf, 12);
    buf[13] = '\0';
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
