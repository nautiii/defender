/*
** EPITECH PROJECT, 2019
** collis
** File description:
** collis
*/

#include "defender.h"

int mouse(sfRenderWindow *window, collis_t *cursor)
{
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    cursor->curstex = sfTexture_createFromFile("ressources/lol.png", NULL);
    cursor->t_destroy = sfTexture_createFromFile("ressources/cross.png" , NULL);
    cursor->m_destroy = sfMusic_createFromFile(SOUND_DEL);
    if (!cursor->curstex || !cursor->t_destroy || !cursor->m_destroy)
        return (-1);
    cursor->c_destroy = sfClock_create();
    create_sprite(&cursor->curspr, cursor->curstex);
    cursor->catch = NULL;
    cursor->s_destroy = NULL;
    cursor->offset_x = 0;
    cursor->offset_y = 0;
    cursor->price = 0;
    return (0);
}

void mouse_pos(sfRenderWindow *window, collis_t *c)
{
    c->x = sfMouse_getPositionRenderWindow(window).x + c->offset_x;
    c->y = sfMouse_getPositionRenderWindow(window).y + c->offset_y;
    sfSprite_setPosition(c->curspr, create_vector2f(c->x, c->y));
}
