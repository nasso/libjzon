/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON string deserializer
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_str(const jzon_t jz, const jzon_type_desc_t *item_type,
    void *dest)
{
    char **str = dest;

    (void)(item_type);
    *str = my_cstrdup(jzon_str(jz));
    return (*str == NULL);
}

const jzon_type_desc_t JZON_STR_TYPE_DESC = {
    .primitive = JZ_STR,
    .deser_func = &jzon_deser_str,
    .size = sizeof(char*),
};
