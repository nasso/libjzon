/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON objects unit tests
*/

#include <criterion/criterion.h>
#include "jzon/jzon.h"

Test(objects, get_set_key)
{
    jzon_t jz = jzon_create_obj();

    cr_assert_not(jzon_setk(jz, "foo", jzon_create_str("bar")));
    cr_assert_str_eq(jzon_str(jzon_getk(jz, "foo").v), "bar");
    jzon_drop(jz);
}
