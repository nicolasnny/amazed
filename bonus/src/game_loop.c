/*
** EPITECH PROJECT, 2024
** AMAZED
** File description:
** Func for the bonus llop
*/

#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#include "amazed.h"

static bool timer(double sec)
{
    static int first = 1;
    static time_t start = 0;
    time_t current = 0;

    time(&current);
    if (first)
        time(&start);
    first = 0;
    if ((current - start) >= sec) {
        time(&start);
        return true;
    }
    return false;
}

static bool timer2(double sec)
{
    static int first = 1;
    static time_t start = 0;
    time_t current = 0;

    time(&current);
    if (first)
        time(&start);
    first = 0;
    if ((current - start) >= sec) {
        time(&start);
        return true;
    }
    return false;
}

static bool check_one_path(path_list_t *path_list)
{
    if (path_list == NULL)
        return false;
    while (path_list->robots) {
        if (!path_list->robots->robot->room->end) {
            return false;
        }
        path_list->robots = path_list->robots->next;
    }
    return true;
}

static bool game_finished(path_list_t *path_list)
{
    path_list_t *path_list_cpy = path_list;

    if (path_list_cpy == NULL)
        return false;
    while (path_list_cpy) {
        if (!check_one_path(path_list_cpy)) {
            return false;
        }
        path_list_cpy = path_list_cpy->next;
    }
    return true;
}

static void recursive_move(robot_list_t *robots)
{
    if (robots == NULL || robots->robot == NULL)
        return;
    recursive_move(robots->next);
    if (robots->robot->next_room != NULL &&
        (!robots->robot->next_room->node->is_occupied ||
            robots->robot->next_room->node->end)) {
        robots->robot->room->is_occupied = false;
        robots->robot->next_room->node->is_occupied = true;
        robots->robot->room = robots->robot->next_room->node;
        robots->robot->next_room = robots->robot->next_room->next;
    }
}

static void go_to_next_step(path_list_t *path_list)
{
    path_list_t *path_list_cpy = path_list;

    if (path_list == NULL)
        return;
    while (path_list_cpy != NULL && !game_finished(path_list_cpy)) {
        recursive_move(path_list_cpy->robots);
        path_list_cpy = path_list_cpy->next;
    }
}

int start_sim(path_list_t *path_list, double time_before_move)
{
    bool over = false;
    robot_list_t *robot_list = get_robot_list(path_list);

    if (time_before_move <= 0) {
        dprintf(2, "Error: invalid time before robots move\n");
        return ERROR;
    }
    initscr();
    while (!over) {
        clear();
        if (timer(time_before_move)){
            go_to_next_step(path_list);
        }
        display_robots(robot_list);
        if (timer2(REFRESH_TIME))
            refresh();
    }
    endwin();
    return SUCCESS;
}
