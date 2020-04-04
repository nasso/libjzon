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

typedef struct jzon jzon_t;

jzon_t *jzon_from_reader(bufreader_t *reader);
jzon_t *jzon_from_path(const char *path);
jzon_t *jzon_from_file(fd_t *fd);
jzon_t *jzon_from_cstr(const char *str);
void jzon_destroy(jzon_t *self);

RC_DEFINE(jzon_t, jzon, jzon_destroy)

typedef RC(jzon) jzon_ref_t;

struct jzon {
    jzon_ref_t ref;
    const enum {
        JZ_STR,
        JZ_NUM,
        JZ_OBJ,
        JZ_ARR,
        JZ_BOOL,
        JZ_NULL,
    } type;
    union {
        const hash_map_t *obj;
        struct {
            const jzon_ref_t *data;
            usize_t len;
        } arr;
        const char *str;
        f64_t num;
        bool bool_val;
    } u;
};

OPT_DEFINE(jzon_t, jzon)
OPT_DEFINE(jzon_ref_t, jzon_ref)

OPT(jzon_ref) jzon_getq(jzon_ref_t self, const char *query);
OPT(jzon_ref) jzon_get(jzon_ref_t self, const char *key);
OPT(jzon_ref) jzon_ind(jzon_ref_t self, usize_t index);

#endif /* LIBJZON_H */
