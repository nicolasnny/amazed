/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions to find the shortest path
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "amazed.h"

static linked_list_t *create_queue(node_t *root)
{
    linked_list_t *q = malloc(sizeof(linked_list_t));

    if (q == NULL) {
        my_putstr_err("Error: coudn't malloc queue\n");
        return NULL;
    }
    q->node = root;
    q->next = NULL;
    return q;
}

static bool check_node(linked_list_t *queue,
    node_t *current, node_t *node_to_check)
{
    if (node_to_check == NULL ||
        current == NULL || node_to_check->checked == true)
        return false;
    set_as_visited(node_to_check, current);
    add_to_queue(queue, node_to_check);
    return true;
}

static void check_compatibilities(linked_list_t *nodes,
    linked_list_t *queue, int **link_array, node_t *current)
{
    for (unsigned int x = 0; link_array[current->id][x] != END_ARRAY; x++) {
        if (link_array[current->id][x] == LINK)
            check_node(queue, current, get_node_from_id(nodes, x));
    }
}

linked_list_t *find_shortest_path(linked_list_t *nodes,
    int **link_array, node_t *root, node_t *goal)
{
    linked_list_t *queue = create_queue(root);
    node_t *current = NULL;
    node_t *parent = root;

    if (root == NULL || queue == NULL || goal == NULL || nodes == NULL) {
        my_putstr_err("Error while checking 'find ");
        my_putstr_err("shortest path' initialisation\n");
        return NULL;
    }
    set_as_visited(root, parent);
    while (queue->node != NULL) {
        current = get_element_in_queue(queue);
        if (current->id == goal->id) {
            free_queue(queue);
            return get_path(goal, root);
        }
        check_compatibilities(nodes, queue, link_array, current);
    }
    my_putstr_err("Error: didn't find any valid path from root to target\n");
    return NULL;
}
