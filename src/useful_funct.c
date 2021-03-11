/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** useful_funct.c
*/

#include "defender.h"

sfVector2f ret_size(sfTexture *texture)
{
    sfVector2f size;

    size.x = (sfTexture_getSize(texture)).x + 0.;
    size.y = (sfTexture_getSize(texture)).y + 0.;
    size.x = size.x * X_RES / 1920;
    size.y = size.y * Y_RES / 1080;
    return (size);
}

void change_resolution(char **av, window_t *w, int bool)
{
    if (av[1] && av[1][0] == '-' && av[1][1] == 'f') {
        if (bool == 0) {
            X_RES = (sfRenderWindow_getSize(w->window)).x;
            Y_RES = (sfRenderWindow_getSize(w->window)).y;
        } else {
            X_RES = 1366;
            Y_RES = 768;
        }
    }
}

void set_time(char time[6], int min, int sec)
{
    time[0] = min / 10 + 48;
    time[1] = min % 10 + 48;
    time[3] = sec / 10 + 48;
    time[4] = sec % 10 + 48;
}
