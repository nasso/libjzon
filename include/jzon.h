/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON header file
*/

#ifndef LIBJZON_H
#define LIBJZON_H

#include "my/types.h"
#include "my/io/bufreader.h"
#include "my/io/bufwriter.h"
#include "my/collections/hash_map.h"
#include "my/collections/vec.h"

typedef enum {
    JZ_STR,
    JZ_NUM,
    JZ_OBJ,
    JZ_ARR,
    JZ_BOOL,
    JZ_NULL,
} jzon_type_t;

typedef struct {
    const jzon_type_t type;
    union {
        const hash_map_t *obj;
        const vec_t *arr;
        const char *str;
        f64_t num;
        bool bool_val;
    } u;
} jzon_val_t;

void jzon__val_destroy(jzon_val_t *self);

RC_DEFINE(jzon_val_t, jzon, jzon__val_destroy)

typedef RC(jzon) jzon_t;

OPT_DEFINE(jzon_t, jzon)

jzon_t jzon_create_str(const char *val);
jzon_t jzon_create_num(f64_t val);
jzon_t jzon_create_obj(void);
jzon_t jzon_create_arr(usize_t size);
jzon_t jzon_create_bool(bool val);
jzon_t jzon_create_null(void);
jzon_t jzon_from_reader(bufreader_t *reader);
jzon_t jzon_from_path(const char *path);
jzon_t jzon_from_file(fd_t fd);
jzon_t jzon_from_cstr(const char *str);
void jzon_drop(jzon_t self);
OPT(jzon) jzon_getq(jzon_t self, const char *query);
OPT(jzon) jzon_get(jzon_t self, const char *key);
OPT(jzon) jzon_ind(jzon_t self, usize_t index);

#endif /* LIBJZON_H */
