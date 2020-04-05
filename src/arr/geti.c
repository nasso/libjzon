/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** jzon_geti implementation
*/

#include "my/my.h"
#include "my/collections/vec.h"
#include "jzon/jzon.h"

OPT(jzon) jzon_geti(const jzon_t self, usize_t index)
{
    OPT(ptr) ptr_val = NONE(ptr);

    if (self->v->type != JZ_ARR)
        return (NONE(jzon));
    ptr_val = vec_get(self->v->u.arr, index);
    return (ptr_val.is_some ? SOME(jzon, jzon_iref(ptr_val.v)) : NONE(jzon));
}
