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
}

int disp_help(void)
{
    disp_logo();
}
