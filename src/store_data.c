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

static char **separate_by_name(char *buffer, linked_list_t *node_list)
{
    char **res = malloc(sizeof(char *) * 3);
    linked_list_t *temp = node_list;
    int rest_to_cpy = 0;
    int counter = 0;

    res[2] = NULL;
    while (temp && find_str(buffer, temp->node->name) != 0)
        temp = temp->next;
    if (!temp)
        return NULL;
    res[0] = my_strdup(temp->node->name);
    rest_to_cpy = my_strlen(buffer) - my_strlen(temp->node->name);
    res[1] = malloc(sizeof(char) * rest_to_cpy);
    for (int i = my_strlen(buffer) - 1; counter < rest_to_cpy; counter++) {
        res[1][counter] = buffer[i];
        i--;
    }
    res[1][counter - 1] = '\0';
    return res;
}

static int store_data(char **buffer, linked_list_t *node_list, int **map)
{
    char **link = NULL;
    int id_left = 0;
    int id_right = 0;

    for (int i = 0; buffer[i] != NULL; i++) {
        link = separate_by_name(buffer[i], node_list);
        if (link == NULL) {
            my_putstr_err("ERROR: Node not found in the list\n");
            return ERROR;
        }
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
