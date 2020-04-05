/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** JZON from_* constructors
*/

#include "my/my.h"
#include "my/io.h"
#include "jzon/jzon.h"

jzon_t jzon_from_reader(bufreader_t *reader)
{
    (void)(reader);
    return (jzon_create_null());
}

jzon_t jzon_from_path(const char *path)
{
    jzon_t self = NULL;
    bufreader_t *br = filereader_open(path, 1024);

    if (br == NULL)
        return (NULL);
    self = jzon_from_reader(br);
    bufreader_free(br);
    return (self);
}

jzon_t jzon_from_file(fd_t fd)
{
    jzon_t self = NULL;
    bufreader_t *br = filereader_from(fd, 1024);

    if (br == NULL)
        return (NULL);
    self = jzon_from_reader(br);
    bufreader_free(br);
    return (self);
}

jzon_t jzon_from_cstr(const char *cstr)
{
    jzon_t self = NULL;
    bufreader_t *br = cstrreader_new(cstr, 1024);

    if (br == NULL)
        return (NULL);
    self = jzon_from_reader(br);
    bufreader_free(br);
    return (self);
}
