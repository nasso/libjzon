/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON array deserializers
*/

#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static bool jzon_deser_arr_size(const jzon_t jz,
    const jzon_type_desc_t *item_type, void *dest)
{
    (void)(item_type);
    *((usize_t*) dest) = jzon_len(jz);
    return (false);
}

static bool jzon_deser_heap_arr(const jzon_t jz,
    const jzon_type_desc_t *item_type, void *dest)
{
    void **arr = dest;

    *arr = my_malloc(jzon_len(jz) * item_type->size);
    if (*arr == NULL)
        return (true);
    for (usize_t i = 0; i < jzon_len(jz); i++) {
        if (jzon_deser(jzon_geti(jz, i), item_type, NULL,
            ((char*) *arr) + i * item_type->size)) {
            my_free(arr);
            return (true);
        }
    }
    return (false);
}

const jzon_type_desc_t JZON_ARR_SIZE_TYPE_DESC = {
    .primitive = JZ_ARR,
    .deser_func = &jzon_deser_arr_size,
    .size = sizeof(usize_t),
};

const jzon_type_desc_t JZON_HEAP_ARR_TYPE_DESC = {
    .primitive = JZ_ARR,
    .deser_func = &jzon_deser_heap_arr,
    .size = sizeof(void*),
    .is_ptr = true,
};
