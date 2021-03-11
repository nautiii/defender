/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main.c
*/

#include "defender.h"

static int help(void)
{
    mputstr("USAGE\n\t./my_defender [-f] [X_RESOLUTION] [Y_RESOLUTION]\n\n");
    mputstr("DESCRIPTION\n\toptions: -f\tset the game in full screen.\n\t\t");
    mputstr(" X_RESOLUTION\tset x resolution to X_RESOLUTION value.\n\t\t");
    mputstr(" Y_RESOLUTION\tset y resolution to Y_RESOLUTION value.\n\t");
    mputstr("no option: set the game in 1366x768\n");
    return (0);
}

static void set_resolution(int ac, char **av)
{
    X_RES = (ac > 1 && mgetnbr(av[1]) > 0) ? mgetnbr(av[1]) : 1366;
    Y_RES = (ac > 2 && mgetnbr(av[2]) > 0) ? mgetnbr(av[2]) : 768;
}

int main(int ac, char **av)
{
    set_resolution(ac, av);
    return (mstrcmp(av[1], "-h") == 0) ? help(): (defender(av, 0));
}
