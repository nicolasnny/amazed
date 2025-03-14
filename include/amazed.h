/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#include <stdbool.h>
#include "struct.h"

#ifndef AMAZED_H
    #define AMAZED_H

    #include <stdbool.h>
    #include "my.h"
    #include "struct.h"

    #define SUCCESS 0
    #define ERROR 84
    #define SYS_ERROR -1
    #define END_ARRAY -1
    #define LINK 1
    #define NO_LINK 0

// --> linked list
int add_to_queue(linked_list_t **queue, node_t *node);
unsigned int get_list_size(linked_list_t *list);
void display_list_name(linked_list_t *list);

// --> nodes
node_t *get_element_in_queue(linked_list_t **queue);
void set_as_visited(node_t *node, node_t *parent);
node_t *get_node_from_id(linked_list_t *list, int id);
node_t *get_root_node(linked_list_t *list);
node_t *get_goal_node(linked_list_t *list);

// --> algorithm
linked_list_t *find_shortest_path(linked_list_t *nodes, int **link_array);
linked_list_t *get_path(node_t *goal, node_t *root);
void set_map_to_find_new_path(linked_list_t *nodes, path_list_t *paths);

// --> clean
int free_queue(linked_list_t *queue);
void main_free(linked_list_t *rooms, path_list_t *path_list, char **data);
void free_input(input_t *input);

// --> links bewteen nodes
int **init_map(char **buffer, linked_list_t *node_list);
unsigned int get_links_nb(int **link_array, node_t *node);
linked_list_t *get_rooms(char **array);
char **get_connections(char **array);
int amazed(void);
char **get_valid_part(char **line_array);
int **init_map(char **buffer, linked_list_t *node_list);

// --> robot spreading
path_list_t *spread_robots(linked_list_t *rooms, path_list_t *paths,
    char **data);
path_list_t *get_path_list(char **data, linked_list_t *rooms,
    int **link_array);

// --> help prompt
int disp_help(void);

int get_nb_valid_lines(char **line_array);
bool valid_robot_quantity(char **array);

// --> output
void print_basic_output(linked_list_t *rooms, char **data,
    char **connections, path_list_t *path_list);
char *id2name(int id, linked_list_t *node_list);
void move_robots(path_list_t *path_list);

#endif /*   A_MAZE_D    */
