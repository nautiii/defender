/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** map.h
*/

#ifndef MAP_H
#define MAP_H

#include "csfml.h"

static const char CASTLE[] = "ressources/castle.png";
static const char MAP_GROUND[] = "ressources/sol_decor.png";
static const char MIST[] = "ressources/mist.png";
static const char BLACK_ZONE[] = "ressources/black_zone.png";
static const char LOAD[] = "ressources/load_wave.png";
static const char FONT[] = "ressources/towerruinsexpand.ttf";
static const char MUSIC_LOOP[] = "ressources/sound/main_loop.ogg";

typedef struct window_s {
    sfRenderWindow *window;
    sfView *view;
    int restart;
    sfMusic *loop;
} window_t;

typedef struct brm_s {
    sfSprite *s_brm;
    sfSprite *s_black;
    sfTexture *t_brm;
    sfTexture *t_black;
    sfVector2f p_brm;
} brm_t;

typedef struct chrono_s {
    sfSprite *s_chrono;
    sfTexture *t_chrono;
    sfClock *c_chrono;
    sfVector2f p_chrono;
    sfVector2f txt_pos;
    sfIntRect r_chrono;
    sfText *txt_chrono;
    sfFont *f_chrono;
    int minutes;
    int secondes;
    char time[6];
    int time_limit;
} chrono_t;

typedef struct map_s {
    window_t window;
    sfSprite *s_map;
    sfTexture *t_map;
    sfVector2f p_map;
    brm_t mist;
    chrono_t chrono;
} map_t;

void change_resolution(char **av, window_t *w, int bool);
int init_map(map_t *map);

#endif
