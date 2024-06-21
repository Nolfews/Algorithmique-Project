/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** rush-1-4
*/

void error_handler(int x , int y)
{
    int j = 0;
    int i = 0;

    if (x > 1 && y == 1) {
        while (i < x) {
        my_putchar('B');
        i++;
        }
        my_putchar('\n');
    }
    if (x == 1 && y > 1) {
        while (j < y) {
            my_putchar('B');
            my_putchar('\n');
            j++;
        }
    }
    if (x == 1 && y == 1) {
        write(1, "B\n", 3);
    }
}

void top_handler(int x, int y)
{
    int i = 0;

    my_putchar('A');
    while (i < x - 2) {
        my_putchar('B');
        i++;
    }
    my_putchar('C');
    my_putchar('\n');
}

void end_handler(int x, int y)
{
    int i = 0;

    my_putchar('A');
    while (i < x - 2) {
        my_putchar('B');
        i++;
    }
    my_putchar('C');
    my_putchar('\n');
}

void mid_handler(int x, int y)
{
    int i;
    int j = 0;
    int space = 0;

    while (j < y - 2) {
        my_putchar('B');
        while (space < x - 2) {
            my_putchar(' ');
            space++;
        }
        my_putchar('B');
        my_putchar('\n');
        space = 0;
        j++;
    }
}

void rush(int x, int y)
{
    int i = 0;
    int j = 0;

    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 14);
    }
    error_handler(x, y);
    if (x > 2 && y > 2) {
    top_handler(x, y);
    mid_handler(x, y);
    end_handler(x, y);
    }
}
