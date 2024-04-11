/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Functions related to the displaying of robots
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "amazed.h"

static void get_height_and_width(char **map, int *height, int *width)
{
    int line = 0;
    int col = 0;
    int m_col = 0;

    while (map[line] != NULL) {
        while (map[line][col] != '\0')
            col++;
        line++;
        if (col > m_col)
            m_col = col;
    }
    *width = m_col;
    *height = line;
    dprintf(2, "Hieght not normal: %d\n", *height);
}

static void display_map(char **map, int cols_before)
{
    int line = 0;
    int height;
    int width;

    get_height_and_width(map, &height, &width);
    if (LINES < height + 2 || COLS < width + cols_before) {
        move(LINES / 2, COLS / 2 - 27 / 2);
        printw("Please resize the terminal\n");
    } else {
        while (map[line] != NULL) {
            move(LINES / 2 - height / 2 + line, cols_before + 1);
            printw("%s\n", map[line]);
            line++;
        }
    }
}

static void add_robot(robot_list_t **list, robot_t *robot)
{
    robot_list_t *element = malloc(sizeof(robot_list_t));

    element->next = *list;
    element->robot = robot;
    *list = element;
}

void add_robot_to_list(robot_list_t *robot_list,
    robot_list_t **new_list, enum room_type room)
{
    while (robot_list != NULL) {
        if (room == Start && robot_list->robot->room->start) {
            add_robot(new_list, robot_list->robot);
        }
        if (room == End && robot_list->robot->room->end) {
            add_robot(new_list, robot_list->robot);
        }
        if (room != Start && room != End &&
            !robot_list->robot->room->end && !robot_list->robot->room->start) {
            add_robot(new_list, robot_list->robot);
        }
        robot_list = robot_list->next;
    }
}

void display_robots(robot_list_t *robots_list)
{
    char **start_room = create_group_box(robots_list, Start);
    char **middle_room = create_group_box(robots_list, Middle);
    char **end_room = create_group_box(robots_list, End);
    int cols_before = 0;

    display_map(start_room, cols_before);
    cols_before += (COLS - 15) / 3 + 2;
    display_map(middle_room, cols_before);
    cols_before = (COLS - 15) / 3 * 2 + 2 * 2;
    display_map(end_room, cols_before);
}
