/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** case_error
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../includes/my.h"

static void check_if_all_car_valid(char *buf)
{
    for (int i = 0; i < strlen(buf); i++) {
        if (buf[i] != 'X' && buf[i] != '.' && buf[i]
            != '\n' && buf[i] != '\0') {
            exit(84);
        }
    }
}

static void check_if_all_strlen_same(char *filepath)
{
    char **array = parsing_file(filepath);
    int len = strlen(array[0]);

    if (len_tab(array) == 1)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        if (strlen(array[i]) != len)
            exit(84);
    }
    free_array(array);
}

static void check_if_valid_file(char *file)
{
    int fd = open(file, O_RDONLY);
    struct stat sb;
    char *buf = NULL;

    if (fd == -1)
        exit(84);
    stat(file, &sb);
    if (S_ISREG(sb.st_mode) && sb.st_size != 0) {
        buf = malloc(sizeof(char) * sb.st_size + 1);
        read(fd, buf, sb.st_size);
        buf[sb.st_size] = '\0';
        check_if_all_car_valid(buf);
        check_if_all_strlen_same(file);
        free(buf);
    } else {
        close(fd);
        exit(84);
    }
    close(fd);
}

static void check_if_valid_number(char *number)
{
    for (int i = 0; i < strlen(number); i++) {
        if (number[i] < '0' || number[i] > '9')
            exit(84);
    }
}

void case_error(int argc, char **argv)
{
    if (argc != 3)
        exit(84);
    check_if_valid_file(argv[1]);
    check_if_valid_number(argv[2]);
}
