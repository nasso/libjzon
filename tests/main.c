/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include "jzon/jzon.h"

Test(libjzon, it_works)
{
    cr_assert_eq(jz_add(2, 2), 4);
}
