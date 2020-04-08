/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON getq implementation
*/

#include "my/my.h"
#include "jzon/jzon.h"

static jzon_t process_query(const char **query, const jzon_t jz)
{
    char *key = NULL;
    usize_t key_len = 0;
    jzon_t child = NULL;

    if (**query != '.')
        return (NULL);
    (*query)++;
    key_len = my_cstrchrnul(*query, '.') - *query;
    key = my_cstrndup(*query, key_len);
    *query += key_len;
    if (key == NULL)
        return (NULL);
    child = jzon_getk(jz, key);
    my_free(key);
    return (child);
}

jzon_t jzon_getq(const jzon_t self, const char *query)
{
    jzon_t jz = jzon_iref(self);
    jzon_t sub_jz = NULL;

    while (jz != NULL && *query != '\0') {
        sub_jz = process_query(&query, jz);
        jzon_drop(jz);
        jz = sub_jz;
    }
    return (jz);
}
