/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#include <stdbool.h>

#ifndef A_MAZE_D
    #define A_MAZE_D
    #define SUCCESS 0
    #define ERROR 84

typedef struct node_s {
    char *name;
    int id;
    bool checked;
    bool end;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

int init_map(char **buffer, linked_list_t *node_list);
#endif /*   A_MAZE_D    */
