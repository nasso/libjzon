/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_getq and jzon_getk implementations
*/

#include "my/my.h"
#include "my/collections/hash_map.h"
#include "jzon/jzon.h"

OPT(jzon) jzon_getq(const jzon_t self, const char *query)
{
    (void)(self);
    (void)(query);
    return (NONE(jzon));
}

OPT(jzon) jzon_getk(const jzon_t self, const char *key)
{
    OPT(ptr) val = NONE(ptr);

    if (self->v->type != JZ_OBJ)
        return (NONE(jzon));
    val = hash_map_get(self->v->u.obj, key);
    return (val.is_some ? SOME(jzon, jzon_iref(val.v)) : NONE(jzon));
}
