/*
** EPITECH PROJECT, 2020
** libjzon
** File description:
** JZON deserializer tests
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "jzon/jzon.h"
#include "jzon/deser.h"

static const char *SAMPLE_MAP =
    "{"
    "   \"name\": \"Gay Zone\","
    "   \"layers\": ["
    "       {"
    "           \"size\": {\"width\": 4, \"height\": 2},"
    "           \"tiles\": [5, 3, 8, 4, 9, 6, 2, 7]"
    "       },"
    "       {"
    "           \"size\": {\"width\": 3, \"height\": 3},"
    "           \"tiles\": [9, 5, 3, 8, 4, 6, 2, 8, 5]"
    "       },"
    "       {"
    "           \"size\": {\"width\": 2, \"height\": 5},"
    "           \"tiles\": [7, 5, 8, 6, 3, 5, 1, 8, 2, 5]"
    "       }"
    "   ]"
    "}";

struct layer {
    struct {
        usize_t width;
        usize_t height;
    } size;
    u64_t *tiles;
};

struct map {
    char *name;
    struct layer *layers;
    usize_t layer_count;
};

static const jzon_type_desc_t LAYER_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(struct layer),
    .fields = {
        {
            .match = ".size.width",
            .offset = offsetof(struct layer, size.width),
            .type = &JZON_USIZE_TYPE_DESC,
        },
        {
            .match = ".size.height",
            .offset = offsetof(struct layer, size.height),
            .type = &JZON_USIZE_TYPE_DESC,
        },
        {
            .match = ".tiles",
            .offset = offsetof(struct layer, tiles),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .item_type = &JZON_U64_TYPE_DESC,
        },
    },
};

static const jzon_type_desc_t MAP_TYPE_DESC = {
    .primitive = JZ_OBJ,
    .size = sizeof(struct map),
    .fields = {
        {
            .match = ".name",
            .offset = offsetof(struct map, name),
            .type = &JZON_STR_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(struct map, layers),
            .type = &JZON_HEAP_ARR_TYPE_DESC,
            .item_type = &LAYER_TYPE_DESC,
        },
        {
            .match = ".layers",
            .offset = offsetof(struct map, layer_count),
            .type = &JZON_ARR_SIZE_TYPE_DESC,
        },
    },
};

Test(deser, map)
{
    struct map map = {0};
    static const u64_t TILES_1[] = {5, 3, 8, 4, 9, 6, 2, 7};
    static const u64_t TILES_2[] = {9, 5, 3, 8, 4, 6, 2, 8, 5};
    static const u64_t TILES_3[] = {7, 5, 8, 6, 3, 5, 1, 8, 2, 5};

    cr_assert_not(jzon_deser_cstr(SAMPLE_MAP, &MAP_TYPE_DESC, NULL, &map));
    cr_assert_str_eq(map.name, "Gay Zone");
    cr_assert_eq(map.layer_count, 3);
    cr_assert_eq(map.layers[0].size.width, 4);
    cr_assert_eq(map.layers[0].size.height, 2);
    cr_assert_arr_eq(map.layers[0].tiles, TILES_1, 8);
    cr_assert_eq(map.layers[1].size.width, 3);
    cr_assert_eq(map.layers[1].size.height, 3);
    cr_assert_arr_eq(map.layers[1].tiles, TILES_2, 9);
    cr_assert_eq(map.layers[2].size.width, 2);
    cr_assert_eq(map.layers[2].size.height, 5);
    cr_assert_arr_eq(map.layers[2].tiles, TILES_3, 10);
}
