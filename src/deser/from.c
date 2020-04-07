/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON deserializer from different sources
*/

#include "jzon/jzon.h"
#include "jzon/deser.h"

bool jzon_deser_path(const char *path, const jzon_type_desc_t *type_desc,
    void *dest)
{
    jzon_t jz = jzon_from_path(path);
    bool err = false;

    if (jz == NULL)
        return (true);
    err = jzon_deser(jz, type_desc, dest);
    jzon_drop(jz);
    return (err);
}

bool jzon_deser_file(fd_t fd, const jzon_type_desc_t *type_desc, void *dest)
{
    jzon_t jz = jzon_from_file(fd);
    bool err = false;

    if (jz == NULL)
        return (true);
    err = jzon_deser(jz, type_desc, dest);
    jzon_drop(jz);
    return (err);
}

bool jzon_deser_cstr(const char *str, const jzon_type_desc_t *type_desc,
    void *dest)
{
    jzon_t jz = jzon_from(str);
    bool err = false;

    if (jz == NULL)
        return (true);
    err = jzon_deser(jz, type_desc, dest);
    jzon_drop(jz);
    return (err);
}

bool jzon_deser_reader(bufreader_t *reader, const jzon_type_desc_t *type_desc,
    void *dest)
{
    jzon_t jz = jzon_from_reader(reader);
    bool err = false;

    if (jz == NULL)
        return (true);
    err = jzon_deser(jz, type_desc, dest);
    jzon_drop(jz);
    return (err);
}

