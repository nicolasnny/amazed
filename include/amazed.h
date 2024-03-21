/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** amazed.h
*/

#ifndef A_MAZE_D
    #define A_MAZE_D
    #define SUCCESS 0
    #define ERROR 84

typedef struct node_s {
    unsigned int x;
    unsigned int y;
    int checked;
    struct node_s *parent;
} node_t;

typedef struct queue_s {
    node_t *node;
    struct queue_s *next;
} queue_t;

#endif /*   A_MAZE_D    */
