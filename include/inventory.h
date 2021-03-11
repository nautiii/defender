/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** inventory.h
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include "csfml.h"
#include "building.h"

static const char INVENTORY[] = "ressources/rhudmenu.png";
static const char SKIP[] = "ressources/skip.png";
static const char DELETE[] = "ressources/delete.png";
static const char SOUND_DEL[] = "ressources/sound/delete.ogg";

typedef struct tower_s {
    sfSprite *s_tower;
    sfTexture *t_tower;
    sfVector2f p_tower;
} tower_t;

typedef struct money_s {
    int gold;
    sfText *txt_money;
    sfClock *c_money;
    char str_money[9];
    sfVector2f p_money;
} money_t;

typedef struct button_s {
    sfSprite *s_button;
    sfTexture *t_button;
    sfVector2f p_button;
} button_t;

typedef struct score_s {
    int nb;
    sfText *txt_score;
    sfClock *c_score;
    char str_score[13];
    sfVector2f p_score;
} score_t;

typedef struct inventory_s {
    sfSprite *s_inventory;
    sfTexture *t_inventory;
    sfVector2f p_inventory;
    castle_t castle;
    tower_t tower[8];
    button_t button[2];
    turret_t *turret;
    money_t money;
    score_t score;
} inventory_t;

int init_buttons(button_t button[2]);

#endif
