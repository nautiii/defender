/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** cursor.h
*/

#ifndef CURSOR_H
#define CURSOR_H

#include "csfml.h"
#include "menu.h"

typedef struct collis_s {
    int x;
    int y;
    int offset_x;
    int offset_y;
    sfTexture *curstex;
    sfSprite *curspr;
    sfIntRect curs_rect;
    sfSprite *catch;
    sfSprite *s_destroy;
    sfTexture *t_destroy;
    sfClock *c_destroy;
    sfMusic *m_destroy;
    int type;
    int price;
} collis_t;

int mouse(sfRenderWindow *window, collis_t *col);
void mouse_pos(sfRenderWindow *window, collis_t *col);
int coll(sfRenderWindow *w, collis_t *col, menu_t menu[6]);

#endif
