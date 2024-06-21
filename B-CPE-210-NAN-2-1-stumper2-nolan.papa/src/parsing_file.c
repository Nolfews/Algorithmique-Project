/*
** EPITECH PROJECT, 2024
** stumper2
** File description:
** parsing file
*/

#include "../includes/my.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

char **parsing_file(char *filepath)
{
    char **array = NULL;
    int fd = open(filepath, O_RDONLY);
    char *str = NULL;
    struct stat sb;

    stat(filepath, &sb);
    str = malloc(sizeof(char) * sb.st_size + 1);
    read(fd, str, sb.st_size);
    str[sb.st_size] = '\0';
    array = str_to_array(str, "\n");
    close(fd);
    free(str);
    return (array);
}
