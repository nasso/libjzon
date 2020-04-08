/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON getq unit tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"

static const f64_t EPSILON = 0.00001;

static const char *SAMPLE_JSON =
    "{"
    "   \"foo\": \"bar\","
    "   \"bar\": \"foo\","
    "   \"hello\": 58,"
    "   \"some_obj\": {"
    "       \"inner\": \"value\","
    "       \"inner_obj\": { \"nice\": 69 },"
    "       \"arr\": [420, 69, 621],"
    "       \"nothing\": null"
    "   }"
    "}";

Test(getq, simple_field)
{
    jzon_t jz = jzon_from(SAMPLE_JSON);

    cr_assert_str_eq(jzon_str(jzon_getq(jz, ".foo")), "bar");
    cr_assert_str_eq(jzon_str(jzon_getq(jz, ".bar")), "foo");
    jzon_drop(jz);
}

Test(getq, multi_field)
{
    jzon_t jz = jzon_from(SAMPLE_JSON);

    cr_assert_str_eq(jzon_str(jzon_getq(jz, ".some_obj.inner")), "value");
    cr_assert_float_eq(jzon_num(jzon_getq(jz, ".some_obj.inner_obj.nice")), 69,
        EPSILON);
    jzon_drop(jz);
}

Test(getq, array_fetch)
{
    jzon_t jz = jzon_from(SAMPLE_JSON);

    cr_assert_float_eq(jzon_num(jzon_getq(jz, ".some_obj  . arr[0]")), 420,
        EPSILON);
    cr_assert_float_eq(jzon_num(jzon_getq(jz, " .some_obj.  arr[ 1  ] ")), 69,
        EPSILON);
    cr_assert_float_eq(jzon_num(jzon_getq(jz, ".some_obj .arr [   002]")), 621,
        EPSILON);
    jzon_drop(jz);
}
