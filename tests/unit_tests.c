/*
** EPITECH PROJECT, 2024
** unit_tests
** File description:
** function that allow me to test my program
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "../include/amazed.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

/* linked_list */

Test(unit_test, add_to_queue)
{
    linked_list_t *queue = malloc(sizeof(linked_list_t));
    node_t node = {0};

    cr_assert_eq(add_to_queue(&queue, &node), SUCCESS);
}

/*Test(unit_test, get_element_in_queue)
{
    linked_list_t queue;
    node_t node = {0};
    node_t node1 = {0};
    node_t node2 = {0};
    node_t node3 = {0};

    node.id = 0;
    node1.id = 1;
    node2.id = 2;
    node3.id = 3;
    cr_assert_eq(add_to_queue(&queue, &node), SUCCESS);
    cr_assert_eq(add_to_queue(&queue, &node1), SUCCESS);
    cr_assert_eq(add_to_queue(&queue, &node2), SUCCESS);
    cr_assert_eq(add_to_queue(&queue, &node3), SUCCESS);
    cr_assert_not_null(get_element_in_queue(&queue));
    }*/

Test(unit_tests, set_node_as_visited)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *parent = malloc(sizeof(node_t));

    set_as_visited(node, parent);
}

Test(unit_test, find_shortest_path_with_wrong_initializers)
{
    int a1[] = {14, 45, END_ARRAY};
    int a2[] = {14, 45, END_ARRAY};
    int a3[] = {4, 45, END_ARRAY};
    int *link_array[] = {a1, a2, a3, NULL};

    cr_assert_null(find_shortest_path(NULL, link_array));
    cr_assert_null(find_shortest_path(NULL, link_array));
}
