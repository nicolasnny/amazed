/*
** EPITECH PROJECT, 2024
** 	AMAZED
** File description:
** Main for ncurse
*/

#include <stdbool.h>
#include <ncurses.h>

int start_sim(linked_list_t *robot_list)
{
    bool over = false;
    int key = 0;
    bool move_robots = true;

    initsrc();
    cbreak();
    while (!over) {
        analyse_key(key, &over, &move_robots);
        if (move_robots)
            go_to_next_step(); //n + 1 on the algorithm
        display_robots(robot_list);
    }
    endwin();
}
