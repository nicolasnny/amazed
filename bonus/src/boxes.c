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
        if (i < nsize - 1)
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

    line[col] = '|';
    while ((int)col < size - 1) {
        if (get_robot_list_size(*robot_list) != 0)
            add_robot(robot_list, line + col);
        for (int i = 0; i < ROBOT_CHAR_SIZE; i++)
            line[col + i] = ' ';
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
    for (int i = 1; i < size - 1; i++)
        line[i] = '-';
    line[size - 1] = '*';
    line[size] = '\0';
    return line;
}

char **create_group_box(robot_list_t *robots_list, enum room_type room)
{
    robot_list_t *room_list = NULL;
    add_robot_to_list(robots_list, &room_list, room);
    int max_size = (COLS - 15) / 3;
    int robot_nb = get_robot_list_size(room_list);
    int robots_per_line = max_size / ROBOT_CHAR_SIZE;
    char **box = malloc(sizeof(char *) * (LINES * 0.8 + 1));
    int rb_remains = get_robot_list_size(robots_list);

    dprintf(2, "room(%d)->robots on line: %d | malloc size: %d\n", (int)room, robot_nb, robot_nb / robots_per_line + 3);
    box[0] = create_ending_lines(robots_per_line * ROBOT_CHAR_SIZE + 2);
    for (int line = 1; line < robot_nb / robots_per_line - 1; line++) {
        if (rb_remains >= robots_per_line)
            box[line] = create_new_line(&robots_list, max_size + my_strlen("||"));
        rb_remains = get_robot_list_size(robots_list);
    }
    if (rb_remains != 0)
        dprintf(2, "Error: there shouldn't be any robot remaining at this point\n");
    box[LINES * 0.8 - 1] = create_ending_lines(robots_per_line * ROBOT_CHAR_SIZE + 2);
    box[LINES * 0.8] = NULL;
    return box;
}
