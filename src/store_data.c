/*
** EPITECH PROJECT, 2024
** store_data
** File description:
** all data storage related function
*/

#include <stdio.h>
#include <stdlib.h>
#include "amazed.h"
#include "my.h"
#include "struct.h"

static void fill_matrix(int **map, int matrix_size)
{
    for (int y = 0; y != matrix_size; y++) {
        map[y] = malloc(sizeof(int) * (matrix_size + 1));
        map[y][matrix_size] = -1;
        for (int x = 0; x != matrix_size; x++)
            map[y][x] = 0;
    }
}

static int get_room_nb(linked_list_t *node_list)
{
    linked_list_t *temp = node_list;
    int res = 0;

    while (temp) {
        if (temp->node->id > res)
            res = temp->node->id;
        temp = temp->next;
    }
    return res;
}

static int name2id(char *name, linked_list_t *node_list)
{
    while (node_list) {
        if (my_strcmp(node_list->node->name, name) == 0)
            return node_list->node->id;
        node_list = node_list->next;
    }
    return -1;
}

static int store_data(char **buffer, linked_list_t *node_list, int **map)
{
    char **link = NULL;
    int id_left = 0;
    int id_right = 0;

    for (int i = 0; buffer[i] != NULL; i++) {
        link = my_str_to_word_array(buffer[i], "-");
        if (link[1] == NULL)
            return ERROR;
        id_left = name2id(link[0], node_list);
        id_right = name2id(link[1], node_list);
        map[id_left][id_right] = 1;
        map[id_right][id_left] = 1;
    }
    return SUCCESS;
}

int **init_map(char **buffer, linked_list_t *node_list)
{
    int maxtrix_size = get_room_nb(node_list) + 1;
    int **map = NULL;

    if (maxtrix_size == -1)
        return NULL;
    map = malloc(sizeof(int *) * (maxtrix_size + 1));
    if (map == NULL)
        return NULL;
    map[maxtrix_size] = NULL;
    fill_matrix(map, maxtrix_size);
    if (store_data(buffer, node_list, map) == ERROR)
        return NULL;
    return map;
}
