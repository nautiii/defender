/*
** EPITECH PROJECT, 2019
** defender
** File description:
** useful_csfml_funct.c
*/

#include "defender.h"

sfRenderWindow *create_window(char **av, char *n)
{
    sfRenderWindow *w = NULL;
    sfVideoMode mode = {X_RES, Y_RES, 32};

    if (av[1] && av[1][0] == '-' && av[1][1] == 'f') {
        mode = sfVideoMode_getDesktopMode();
        w = sfRenderWindow_create(mode, n, sfClose | sfFullscreen, NULL);
    } else
        w = sfRenderWindow_create(mode, n, sfClose | sfResize, NULL);
    if (!w)
        return (NULL);
    sfRenderWindow_setFramerateLimit(w, 120);
    return (w);
}

void create_sprite(sfSprite **sprite, sfTexture *texture)
{
    sfVector2f resize = {(X_RES + 0.) / 1920, (Y_RES + 0.) / 1080};

    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, 1);
    sfSprite_setScale(*sprite, resize);
}

sfVector2f create_vector2f(float x, float y)
{
    sfVector2f new_vector;

    new_vector.x = x;
    new_vector.y = y;
    return (new_vector);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect = {top, left, width, height};

    return (rect);
}

void move_rect(sfClock *clock, sfIntRect *rect, int offset, int max)
{
    if ((sfClock_getElapsedTime(clock)).microseconds > 50000) {
        sfClock_restart(clock);
        rect->left += offset;
        if (rect->left == max)
            rect->left = 0;
    }
}
