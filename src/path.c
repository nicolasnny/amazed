/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Function to get the path from the algorithm
*/

#include <stddef.h>
#include <stdlib.h>
#include "amazed.h"

static int error_handling(linked_list_t *path_list, node_t *root, node_t *goal)
{
    if (root == NULL || goal == NULL)
        return ERROR;
    if (path_list == NULL) {
        my_putstr_err("Error: malloc failed in get_path function\n");
        return ERROR;
    }
    return SUCCESS;
}

linked_list_t *get_path(node_t *root, node_t *goal)
{
    linked_list_t *path_list = malloc(sizeof(linked_list_t));
    node_t *node = goal;

    if (error_handling(path_list, root, goal) == ERROR)
        return NULL;
    path_list = NULL;
    while (node != NULL && node->id != goal->id) {
        add_to_queue(&path_list, node);
        node = node->parent;
    }
    return path_list;
}
