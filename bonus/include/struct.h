/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H
    #include <stdbool.h>

typedef struct robot_s robot_t;

typedef struct node_s {
    int id;
    char *name;
    bool checked;
    bool is_occupied;
    bool start;
    bool end;
    int x;
    int y;
    struct node_s *parent;
} node_t;

typedef struct linked_list_s {
    node_t *node;
    struct linked_list_s *next;
} linked_list_t;

typedef struct robot_list_s {
    robot_t *robot;
    struct robot_list_s *next;
} robot_list_t;

typedef struct path_list_s {
    linked_list_t *path;
    robot_list_t *robots;
    int path_len;
    struct path_list_s *next;
} path_list_t;

typedef struct robot_s {
    int id;
    node_t *room;
    linked_list_t *path;
    linked_list_t *next_room;
} robot_t;

enum room_type {
    Start,
    Middle,
    End
};

#endif /*   STRUCT_H    */
