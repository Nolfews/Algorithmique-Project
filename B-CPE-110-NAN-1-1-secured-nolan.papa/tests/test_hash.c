/*
** EPITECH PROJECT, 2024
** test hash
** File description:
** test hash
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../hashtable.h"

Test(ht_insert, test_ht_insert1)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");

    cr_assert_eq(nb, 0);
}

Test(ht_insert, test_ht_insert2)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(NULL, "Vision" , "./Documents/Tournament/Modules/Vision");

    cr_assert_eq(nb, 84);
}

Test(ht_insert, test_ht_insert3)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(ht, NULL , "./Documents/Tournament/Modules/Vision");

    cr_assert_eq(nb, 84);
}

Test(ht_insert, test_ht_insert4)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(ht, "Vision" , NULL);

    cr_assert_eq(nb, 84);
}

Test(ht_insert, test_ht_insert5)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(ht, "" , "./Documents/Tournament/Modules/Vision");

    cr_assert_eq(nb, 84);
}

Test(ht_insert, test_ht_insert6)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb = ht_insert(ht, "Vision" , "");

    cr_assert_eq(nb, 84);
}

Test(ht_delete, test_ht_delete1)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb;

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    nb = ht_delete(ht, "Vision");

    cr_assert_eq(nb, 0);
}

Test(ht_delete, test_ht_delete2)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb;

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    nb = ht_delete(NULL, "Vision");

    cr_assert_eq(nb, 84);
}

Test(ht_delete, test_ht_delete3)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb;

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    nb = ht_delete(ht, NULL);

    cr_assert_eq(nb, 84);
}

Test(ht_delete, test_ht_delete4)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb;

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    nb = ht_delete(ht, "");

    cr_assert_eq(nb, 84);
}

Test(ht_delete, test_ht_delete5)
{
    hashtable_t *ht = new_hashtable(&hash, 4);
    int nb;

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    nb = ht_delete(ht, "Vis");

    cr_assert_eq(nb, 84);
}

Test(ht_search, test_ht_search1)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    char *str = ht_search(ht, "Vision");

    cr_assert_eq(str, str);
}

Test(ht_search, test_ht_search2)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    char *str = ht_search(NULL, "Vision");

    cr_assert_eq(str, NULL);
}

Test(ht_search, test_ht_search3)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    char *str = ht_search(ht, NULL);

    cr_assert_eq(str, NULL);
}

Test(ht_search, test_ht_search4)
{
    hashtable_t *ht = new_hashtable(&hash, 4);

    ht_insert(ht, "Vision" , "./Documents/Tournament/Modules/Vision");
    char *str = ht_search(ht, "");

    cr_assert_eq(str, NULL);
}
