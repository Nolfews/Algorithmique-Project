/*
** EPITECH PROJECT, 2023
** star
** File description:
** displays a star
*/

void star1(void)
{
    write(1, "   *", 4);
    my_putchar('\n');
    write(1, "*** ***", 7);
    my_putchar('\n');
    write(1, " *   *", 6);
    my_putchar('\n');
    write(1, "*** ***", 7);
    my_putchar('\n');
    write(1, "   *", 4);
    my_putchar('\n');
}

static void first(unsigned int size)
{
    for (int i = 0; i < 3 * size - 1; i++) {
        my_putchar(' ');
    }
    my_putchar('*');
    my_putchar('\n');
}

static void top_cone(unsigned int size)
{
    int reduc = 2;
    int ecart = 1;
    int l;

    for (int j = 0; j < size - 1; j++) {
        for (int k = 0; k < 3 * size - reduc; k++) {
            my_putchar(' ');
        }
        my_putchar('*');
        for (l = 0; l < ecart; l++) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
        reduc++;
        ecart += 2;
    }
}

static void barre(unsigned int size)
{
    for (int i = 0; i < 2 * size + 1; i++) {
        my_putchar('*');
    }
    for (int j = 0; j < 2 * size - 3; j++) {
        my_putchar(' ');
    }
    for (int k = 0; k < 2 * size + 1; k++) {
        my_putchar('*');
    }
    my_putchar('\n');
}

static void top_mid(unsigned int size)
{
    int ecart_left = 1;
    int ecart_center = 6 * size - 4;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < ecart_left; j++) {
            my_putchar(' ');
        }
        my_putchar('*');
        ecart_left++;
        for (int k = 1; k < ecart_center; k++) {
            my_putchar(' ');
        }
        ecart_center -= 2;
        my_putchar('*');
        my_putchar('\n');
    }
}

static void bot_mid(unsigned int size)
{
    int ecart_left = size - 1;
    int ecart_center = 4 * size;

    for (int i = 0; i < size - 1; i++) {
        for (int j = ecart_left; j > 0; j--) {
            my_putchar(' ');
        }
        my_putchar('*');
        ecart_left--;
        for (int k = ecart_center; k > 1; k--) {
            my_putchar(' ');
        }
        ecart_center += 2;
        my_putchar('*');
        my_putchar('\n');
    }
}

static void bot_cone(unsigned int size)
{
    int reduc = 2 * size;
    int ecart = 2 * size - 3;
    int l;

    for (int j = size - 1; j > 0; j--) {
        for (int k = reduc; k > 0; k--) {
            my_putchar(' ');
        }
        reduc++;
        my_putchar('*');
        for (l = ecart ; l > 0; l--) {
            my_putchar(' ');
        }
        my_putchar('*');
        my_putchar('\n');
        l = 0;
        ecart -= 2;
    }
}

static void last(unsigned int size)
{
    for (int i = 0; i < 3 * size - 1; i++) {
        my_putchar(' ');
    }
    my_putchar('*');
    my_putchar('\n');
}

void star(unsigned int size)
{
    if ( size == 1) {
        star1();
    }
    if ( size >= 2) {
        first(size);
        top_cone(size);
        barre(size);
        top_mid(size);
        bot_mid(size);
        barre(size);
        bot_cone(size);
        last(size);
    }
}
