/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON destroyer
*/

#include "my/my.h"
#include "jzon/jzon.h"

void jzon__val_destroy(jzon_val_t *self)
{
    if (self == NULL)
        return;
    switch (self->type) {
    case JZ_STR:
        my_free((void*) self->u.str);
        break;
    case JZ_OBJ:
        hash_map_destroy((void*) self->u.obj);
        break;
    case JZ_ARR:
        for (usize_t i = 0; i < self->u.arr->len; i++)
            RC_DROP(jzon)(self->u.arr->data[i]);
        vec_destroy((vec_t*) self->u.arr);
    default:
        break;
    }
    my_free(self);
}
