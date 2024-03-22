/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#ifndef AMAZED_H
    #define AMAZED_H

    #include <stdbool.h>
    #include "my.h"
    #include "amazed_struct.h"

    #define SUCCESS 0
    #define ERROR 84
    #define END_ARRAY -1
    #define LINK 1
    #define NO_LINK 0

// --> linked list
int add_to_queue(linked_list_t *queue, node_t *node);

// --> nodes
node_t *get_element_in_queue(linked_list_t *queue);
void set_as_visited(node_t *node, node_t *parent);
node_t *get_node_from_id(linked_list_t *list, int id);

// --> algorithm
path_t *find_shortest_path(linked_list_t *nodes, int **link_array,
    node_t *root, node_t *goal);

// --> clean
int free_queue(linked_list_t *queue);

int file_valid(void);

#endif /*   A_MAZE_D    */
