/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Parsing tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/parser.h"

static const f64_t EPSILON = 0.00001;

Test(parser, parse_null)
{
    jzon_t jz = jzon_from("null");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_NULL);
}

Test(parser, parse_true)
{
    jzon_t jz = jzon_from("true");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_BOOL);
    cr_assert_eq(jzon_bool(jz), true);
}

Test(parser, parse_false)
{
    jzon_t jz = jzon_from("false");

    cr_assert_not_null(jz);
    cr_assert_eq(jz->v->type, JZ_BOOL);
    cr_assert_eq(jzon_bool(jz), false);
}

Test(parser, parse_integer_num)
{
    cr_assert_float_eq(jzon_num(jzon_from("0")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("1")), 1, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("59")), 59, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-63")), -63, EPSILON);
}

Test(parser, parse_floating_point_num)
{
    cr_assert_float_eq(jzon_num(jzon_from("0.0")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("0.0000")), 0, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("1.002")), 1.002, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("59.95")), 59.95, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-63.936")), -63.936, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-0.420")), -0.420, EPSILON);
}

Test(parser, parse_exp_num)
{
    cr_assert_float_eq(jzon_num(jzon_from("0e98")), 0e98, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("9e2")), 9e2, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-7E3")), -7E3, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-37.13e+10")), -37.13e+10, EPSILON);
    cr_assert_float_eq(jzon_num(jzon_from("-37.13e-2")), -37.13e-2, EPSILON);
}
