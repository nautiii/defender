/*
** EPITECH PROJECT, 2019
** pause
** File description:
** pause
*/

#ifndef PAUSE_H
#define PAUSE_H

#include "lib.h"

static const char *PAUSE[4] = {"ressources/parche.png",
                                "ressources/new.png",
                                "ressources/exit.png",
                                "ressources/continue.png"};

typedef struct pause_s {
    sfSprite *s_pause;
    sfTexture *t_pause;
    sfVector2f p_pause;
} pause_t;

int init_pause(pause_t pause[4]);

#endif
