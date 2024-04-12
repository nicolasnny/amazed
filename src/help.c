/*
** EPITECH PROJECT, 2023
** B-CPE-200-PAR-2-1-amazed-enzo.fokwen-rocher
** File description:
** help.c
*/

#include "my.h"

static void disp_logo(void)
{
    mini_printf("-*------*-----*--------*--*---*-----*-----*---*------\n");
    mini_printf("---*--------*-----*-----*-----*-------*--*--------*--\n");
    mini_printf("   ##     ##   ##    ##     #######  #######  #####\n");
    mini_printf("  ####    ### ###   ####    #   ##    ##   #   ## ##\n");
    mini_printf(" ##  ##   #######  ##  ##      ##     ##       ##  ##\n");
    mini_printf(" ##  ##   #######  ##  ##     ##      #####    ##  ##\n");
    mini_printf(" ######   ## # ##  ######    ##       ##       ##  ##\n");
    mini_printf(" ##  ##   ##   ##  ##  ##   ##    #   ##   #   ## ##\n");
    mini_printf(" ##  ##   ##   ##  ##  ##   #######  #######  #####\n");
    mini_printf("-*------*-----*--------*--*---*-----*-----*---*------\n");
    mini_printf("---*--------*-----*-----*-----*-------*--*--------*--\n");
    my_putchar('\n');
}

int disp_help(void)
{
    disp_logo();
    mini_printf("SYNOPSIS\n\t./amazed [OPTION]\n\n");
    mini_printf("DESCRIPTION\n");
    mini_printf("\tMove all the robots in a maze from the entrance to the ");
    mini_printf("exit as fast as possible. The maze and robots ");
    mini_printf("configuration are given in the standard input.\n\n");
    mini_printf("OPTIONS\n\t-h\tdisplay help\n");
    mini_printf("\t-d  [n]\tdisplay robots state live with ncurse (with n");
    mini_printf(" being the time in seconds between each move iteration ");
    mini_printf("(1 by default))\n");
    return 0;
}
