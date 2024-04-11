/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Create the char ** array to display the robots
*/

#include <ncurses.h>
#include <stdlib.h>
#include "amazed.h"

static int get_robot_list_size(robot_list_t *list)
{
    int size = 0;

    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

static void add_robot(robot_list_t **robot_list, char *line)
{
    char *name = NULL;
    int nsize = 0;

    if (*robot_list != NULL) {
        name = my_nb_to_str((*robot_list)->robot->id);
        nsize = my_strlen(name);
        *robot_list = (*robot_list)->next;
    }
    line[0] = 'P';
    for (int i = 1; i < ROBOT_CHAR_SIZE; i++) {
        if (i - 1 < nsize)
            line[i] = name[i - 1];
        else
            line[i] = ' ';
    }
    line[ROBOT_CHAR_SIZE] = ' ';
}

static char *create_new_line(robot_list_t **robot_list, int size)
{
    char *line = malloc(sizeof(char) * (size + 1));
    unsigned int col = 0;

    for (int i = 0; i < size - 1; i++)
        line[i] = ' ';
    line[col] = '|';
    col++;
    while ((int)col < size - 1) {
        if (get_robot_list_size(*robot_list) != 0
            && (int)col + ROBOT_CHAR_SIZE < size - 1) {
            add_robot(robot_list, line + col);
            col += ROBOT_CHAR_SIZE;
        }
        for (int i = 0; (int)col < size - 1 && i < ROBOT_CHAR_SIZE; i++) {
            line[col] = ' ';
            col++;
        }
    }
    line[col] = '|';
    line[col + 1] = '\0';
    return line;
}

static char *create_starting_lines(int size, enum room_type room)
{
    char *line = malloc(sizeof(char) * (size + 1));
    char *states[] = {"Start room", "Transit room", "Final room", NULL};

    line[0] = '*';
    for (int i = 1; i < size - 1; i++) {
        if (i - 1 < my_strlen(states[(int)room]))
            line[i] = states[(int)room][i - 1];
        else
            line[i] = '-';
    }
    line[size - 1] = '*';
    line[size] = '\0';
    return line;
}

static char *create_ending_lines(int size)
{
    char *line = malloc(sizeof(char) * (size + 1));

    line[0] = '*';
    for (int i = 1; i < size - 1; i++)
        line[i] = '-';
    line[size - 1] = '*';
    line[size] = '\0';
    return line;
}

char **create_group_box(robot_list_t *robots_list, enum room_type room)
{
    robot_list_t *room_list = NULL;
    int max_size = (COLS - 15) / 3;
    char **box = malloc(sizeof(char *) * (LINES * 0.8 + 1));

    add_robot_to_list(robots_list, &room_list, room);
    box[0] = create_starting_lines(max_size + 2, room);
    for (int line = 1; line < LINES * 0.8 - 1; line++) {
        box[line] = create_new_line(&room_list, max_size + my_strlen("||"));
    }
    box[(int)(LINES * 0.8) - 1] = create_ending_lines(max_size + 2);
    box[(int)(LINES * 0.8)] = NULL;
    return box;
}
