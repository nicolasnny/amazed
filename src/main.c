/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** main.c
*/

#include "amazed.h"
#include "my.h"

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return disp_help();
    if (argc != 1)
        return ERROR;
    return amazed();
}
