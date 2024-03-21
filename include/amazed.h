/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#ifndef A_MAZE_D
    #define A_MAZE_D

    #include <stdbool.h>

    #define SUCCESS 0
    #define ERROR 84
    #define END_ARRAY -1
    #define LINK 1
    #define NO_LINK 0

typedef struct node_s {
    bool checked;
    bool end;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

typedef struct path_s {
    linked_list_t *list;
    unsigned int lenght;
} path_t;

#endif /*   A_MAZE_D    */
