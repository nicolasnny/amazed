/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** error_handling_test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stddef.h>
#include "amazed.h"
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error_handling, robot_quantity) {
    char *array1[] = {"5", NULL};
    char *array2[] = {"0", NULL};
    char *array3[] = {"-1", NULL};
    char *array4[] = {"", NULL};
    char *array5[] = {"aozjdoazidj", NULL};

    cr_assert(valid_robot_quantity(array1));
    cr_assert(!valid_robot_quantity(array2));
    cr_assert(!valid_robot_quantity(array3));
    cr_assert(!valid_robot_quantity(array4));
    cr_assert(!valid_robot_quantity(array5));
}

Test(error_handling, nb_valid_lines) {
    char *valid_input[] = {
        "34",
        "##start",
        "0 1 0",
        "##end",
        "1 13 0 #bedroom",
        "2 5 0",
        "3 9 0",
        "0-2",
        "2-3",
        "3-1",
        NULL
    };
    char *invalid_input1[] = {"0", NULL};
    char *invalid_input2[] = {"##start", "0 1", NULL};
    char *invalid_input3[] = {"", NULL};

    cr_assert(get_nb_valid_lines(valid_input) == 10);
    cr_assert(get_nb_valid_lines(invalid_input1) == 0);
    cr_assert(get_nb_valid_lines(invalid_input3) == 0);
}

Test(error_handling, valid_part) {
    char *valid_input[] = {
        "34",
        "##start",
        "0 1 0",
        "##end",
        "1 13 0 #bedroom",
        "2 5 0",
        "3 9 0",
        "0-2",
        "2-3",
        "3-1",
        NULL
    };
    char **valid_result = get_valid_part(valid_input);

    cr_assert_not_null(valid_result);
    cr_assert(my_str_array_cmp(valid_result, valid_input));
    cr_assert_null(valid_result[10]);
    free_str_array(valid_result);
}

Test(error_handling, unvalid_room) {
    char *unvalid_input[] = {
        "34",
        "##start",
        "0 1 0",
        "##end",
        "1 13 0 unvalidnoiazhdoi azoidhaiozdh #bedroom",
        "2 5 0",
        "3 9 0",
        "0-2",
        "2-3",
        "3-1",
        NULL
    };
    char **unvalid_result = get_valid_part(unvalid_input);

    cr_assert_not_null(unvalid_result);
    // cr_assert_arr_neq(unvalid_input, unvalid_result, );
    cr_assert_not(my_str_array_cmp(unvalid_result, unvalid_input));
}