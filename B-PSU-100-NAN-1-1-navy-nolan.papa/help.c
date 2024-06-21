/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** help
*/

#include "include/header.h"

static void print_h(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTIONS\n");
    my_putstr("     first_player_pid:\n");
    my_putstr("     only for the 2nd player.");
    my_putstr(" Pid of the first player.\n\n");
    my_putstr("     navy_positions:\n");
    my_putstr("     file representing the positions of the ships.\n");
}

int error_in_file(char *path)
{
    int fd = open(path, O_RDONLY);
    int fr = 0;
    char *buf = malloc(sizeof(char) * 33);
    int nb_boat = 2;

    fr = read(fd, buf, 32);
    buf[32] = '\0';
    for (int i = 0; i < 4; i++) {
        if (buf[0 + i * 8] == nb_boat + i)
            return 84;
        if (buf[1 + i * 8] != ':' || buf[4 + i * 8] != ':')
            return 84;
        if ((buf[2 + i * 8] < 'A' || buf[2 + i * 8] > 'H') ||
            (buf[5 + i * 8] < 'A' || buf[5 + i * 8] > 'H'))
            return 84;
        if ((buf[3 + 1 * 8] < '1' || buf[3 + i * 8] > '8') ||
            (buf[6 + 1 * 8] < '1' || buf[6 + i * 8] > '8'))
            return 84;
    }
    return (0);
}

int error_file(char *path)
{
    int fd = open(path, O_RDONLY);
    int fr = 0;
    char *buf = malloc(sizeof(char) * 100);

    if (fd == - 1)
        return (84);
    fr = read(fd, buf, 50);
    if (fr == -1 || my_strlen(buf) > 31) {
        close(fd);
        return (84);
    }
    close(fd);
    if (error_in_file(path) == 84)
        return (84);
    return (0);
}

int help(int argc, char **argv)
{
    if (argc == 1 || argc >= 4) {
        return 84;
    }
    if (my_cmp(argv[1], "-h") == 0) {
        if (argc == 3) {
            return 84;
        }
            print_h();
            return (1);
    }
    if (argc == 2) {
        if (error_file(argv[1]) == 84)
            return (84);
    }
    if (argc == 3) {
        if (error_file(argv[2]) == 84)
            return (84);
    }
    return (0);
}
