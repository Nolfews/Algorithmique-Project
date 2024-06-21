/*
** EPITECH PROJECT, 2023
** rush one
** File description:
** displays rectangle.
*/

int putligne(int x, int y)
{
    int i;

    for (i = 1; i <= x; i++) {
        if ( i == 1 || i == x) {
            my_putchar(111);
        } else {
            my_putchar(45);
        }
    }
    my_putchar('\n');
}

int error(int x, int y)
{
    if ( x < 0 || y < 0) {
        write(2, "Invalid size\n", 14);
    }
    if ( x == 0 || y == 0) {
        write(2, "Invalid size\n", 14);
    }
}

int putcenter(int x, int y, int const z)
{
    int j;

    if (y - 2 == 0) {
        putligne(x, y);
        return (0);
    }
    if (z == y) {
        putligne(x, y);
    }
    for (j = 1; j <= x; j++) {
        if ( j == 1 || j == x) {
            my_putchar(124);
        } else {
            my_putchar(32);
        }
    }
    my_putchar('\n');
    return (putcenter(x, y - 1, z));
}

void rush(int x, int y)
{
    int z = y;

    error(x, y);
    if ( x >= 1 && y <= 2) {
        putligne(x, y);
    }
    if ( x >= 1 && y > 2) {
        putcenter(x, y, z);
    }
}
