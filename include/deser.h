/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** Deserializing utilities
*/

#ifndef JZON_DESER_H
#define JZON_DESER_H

#include "my/types.h"
#include "my/io/bufreader.h"
#include "jzon/jzon.h"

#ifndef JZON_DESER_MAX_FIELD_COUNT
    #define JZON_DESER_MAX_FIELD_COUNT 128
#endif

typedef bool (jzon_deser_fn_t)(const jzon_t *jz, void *dest);
typedef struct jzon_type_desc jzon_type_desc_t;

struct jzon_type_desc {
    jzon_type_t primitive;
    union {
        jzon_deser_fn_t *deser_func;
        struct {
            const jzon_type_desc_t *type;
        } arr;
        struct {
            usize_t size;
            struct {
                const char *match;
                usize_t offset;
                const jzon_type_desc_t *type;
            } fields[JZON_DESER_MAX_FIELD_COUNT];
        } obj;
    } u;
};

void *jzon_deser_path(const char *path, const jzon_type_desc_t *type_desc);
void *jzon_deser_file(fd_t fd, const jzon_type_desc_t *type_desc);
void *jzon_deser_cstr(const char *str, const jzon_type_desc_t *type_desc);
void *jzon_deser_reader(bufreader_t *reader, const jzon_type_desc_t *type_desc);
void *jzon_deser(const jzon_t jz, const jzon_type_desc_t *type_desc);

#endif /* JZON_DESER_H */
