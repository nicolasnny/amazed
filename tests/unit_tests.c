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
    linked_list_t queue = NULL;
    node_t node = {0};

    cr_assert_eq(add_to_queue(&queue, &node), SUCCESS);
}
