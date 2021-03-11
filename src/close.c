/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** close.c
*/

#include "csfml.h"

void close_event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}
