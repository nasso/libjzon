/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON deserializer
*/

#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool deser_struct(const jzon_t jz, const jzon_type_desc_t *type_desc,
    void *dest)
{
    bool err = false;
    jzon_t sub_jz = NULL;

    for (usize_t i = 0; !err && i < JZON_DESER_MAX_FIELD_COUNT &&
        type_desc->fields[i].match; i++) {
        sub_jz = jzon_getq(jz, type_desc->fields[i].match);
        if (sub_jz == NULL)
            continue;
        err = jzon_deser(sub_jz, type_desc->fields[i].type,
            &type_desc->fields[i].params,
            (char*) dest + type_desc->fields[i].offset);
        jzon_drop(sub_jz);
    }
    return (err);
}

bool jzon_deser(const jzon_t jz, const jzon_type_desc_t *type_desc,
    const jzon_deser_params_t *params, void *dest)
{
    if (type_desc->primitive != jz->v->type)
        return (true);
    else if (type_desc->deser_func)
        return (type_desc->deser_func(jz, params, dest));
    return (deser_struct(jz, type_desc, dest));
}
