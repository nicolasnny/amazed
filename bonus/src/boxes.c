/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Create the char ** array to display the robots
*/

#include <ncurses.h>
#include <stdlib.h>
#include "amazed.h"

static void add_robot(linked_list_t **robot_list, char *line)
{
    char *name = NULL;
    int nsize = 0;

    if (*robot_list != NULL) {
        name = (*robot_list)->robot->name;
        nsize = my_strlen(name);
        *robot_list = (*robot_list)->next;
    }
    line[0] = 'P';
    for (int i = 1; i < 4; i++) {
        if (i < nsize - 1)
            line[i] = name[i - 1];
        else
            line[i] = ' ';
    }
    line[4] = ' ';
}

static char *create_new_line(linked_list_t *robot_list, int size)
{
    char *line = malloc(sizeof(char) * (size + 1));
    unsigned int col = 0;

    line[col] = '|';
    while (col < size - 1) {
        add_robot(robot_list, line + col);
        col += ROBOT_CHAR_SIZE;
    }
    line[col] = '|';
    line[col + 1] = '\0';
    return line;
}

static char *create_ending_lines(int size)
{
    char *line = malloc(sizeof(char) * (size + 1));

    line[0] = '*';
    for (unsigned int i = 1; i < size - 1; i++)
        line[i] = '-';
    line[size - 1] = '*';
    line[size] = '\0';
    return line;
}

char **create_group_box(linked_list_t *robots_list, enum room_type room)
{
    robot_list_t *room_list = NULL;
    add_robot_to_list(robots_list, &room_list, room);
    int max_size = (COLS - 15) / 3;
    int robot_nb = get_list_size(room_list);
    int robots_per_line = max_size / ROBOT_CHAR_SIZE;
    char **box = malloc(sizeof(char *) * (robot_nb / robots_per_line + 3));

    box[0] = create_ending_lines(robots_per_line * ROBOT_CHAR_SIZE + 2);
    for (unsigned int line = 1; line < robot_nb / robots_per_line - 1; line++) {
        box[line] = create_new_line(robots_list, robots_per_line * ROBOT_CHAR_SIZE + 2);
    }
    box[robot_nb / robots_per_line + 2] = create_ending_lines(robots_per_line * ROBOT_CHAR_SIZE + 2);
    return box;
}
