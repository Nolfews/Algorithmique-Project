/*
** EPITECH PROJECT, 2023
** count island
** File description:
** count island
*/

int my_strlength(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

int  replace_island(char **world, int x, int y, int *nb)
{
    int len = my_strlength(world[x]) - 1;

    world[x][y] = *nb + 48;
    if (y + 1 <= len && world[x][y + 1] == 'X') {
        *nb = replace_island(world, x, y + 1, nb);
    }
    if (y - 1 >= 0 && world[x][y - 1] == 'X') {
        *nb = replace_island(world, x, y - 1, nb);
    }
    if (world[x + 1] != 0 && world[x + 1][y] == 'X') {
        *nb = replace_island(world, x + 1, y, nb);
    }
    if (x - 1 >= 0 && world[x - 1][y] == 'X') {
        *nb = replace_island(world, x - 1, y, nb);
    }
    return (*nb);
}

int scan_island(char **world, int x, int y, int *nb)
{
    for (y = 0; world[x][y] != '\0'; y++) {
        if (world[x][y] == 'X') {
            replace_island(world, x, y, nb);
            *nb += 1;
        }
    }
}

int count_island(char **world)
{
    int nb = 0;
    int x = 0;
    int y = 0;

    for (x = 0; world[x] != 0; x++) {
        scan_island(world, x, y, &nb);
    }
    return (nb);
}
