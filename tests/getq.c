/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON getq unit tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"

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
