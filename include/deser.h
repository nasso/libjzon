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

typedef struct jzon_type_desc jzon_type_desc_t;
typedef bool (jzon_deser_fn_t)(const jzon_t jz,
    const jzon_type_desc_t *item_type, void *dest);

struct jzon_type_desc {
    jzon_type_t primitive;
    jzon_deser_fn_t *deser_func;
    usize_t size;
    bool is_ptr;
    struct {
        const char *match;
        usize_t offset;
        const jzon_type_desc_t *type;
        const jzon_type_desc_t *item_type;
    } fields[JZON_DESER_MAX_FIELD_COUNT];
};

extern const jzon_type_desc_t JZON_HASH_MAP_TYPE_DESC;
extern const jzon_type_desc_t JZON_ARR_SIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_HEAP_ARR_TYPE_DESC;
extern const jzon_type_desc_t JZON_STR_TYPE_DESC;
extern const jzon_type_desc_t JZON_U8_TYPE_DESC;
extern const jzon_type_desc_t JZON_U16_TYPE_DESC;
extern const jzon_type_desc_t JZON_U32_TYPE_DESC;
extern const jzon_type_desc_t JZON_U64_TYPE_DESC;
extern const jzon_type_desc_t JZON_USIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_I8_TYPE_DESC;
extern const jzon_type_desc_t JZON_I16_TYPE_DESC;
extern const jzon_type_desc_t JZON_I32_TYPE_DESC;
extern const jzon_type_desc_t JZON_I64_TYPE_DESC;
extern const jzon_type_desc_t JZON_ISIZE_TYPE_DESC;
extern const jzon_type_desc_t JZON_F32_TYPE_DESC;
extern const jzon_type_desc_t JZON_F64_TYPE_DESC;

bool jzon_deser_path(const char *path, const jzon_type_desc_t *type_desc,
    const jzon_type_desc_t *item_type, void *dest);
bool jzon_deser_file(fd_t fd, const jzon_type_desc_t *type_desc,
    const jzon_type_desc_t *item_type, void *dest);
bool jzon_deser_cstr(const char *str, const jzon_type_desc_t *type_desc,
    const jzon_type_desc_t *item_type, void *dest);
bool jzon_deser_reader(bufreader_t *reader, const jzon_type_desc_t *type_desc,
    const jzon_type_desc_t *item_type, void *dest);
bool jzon_deser(const jzon_t jz, const jzon_type_desc_t *type_desc,
    const jzon_type_desc_t *item_type, void *dest);

#endif /* JZON_DESER_H */
