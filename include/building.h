/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** building.h
*/

#ifndef BUILDING_H
#define BUILDING_H

#include "csfml.h"

static const char HEALTH_BAR[] = "ressources/health_bar.png";
static const char CANON[] = "ressources/sound/canon.ogg";
static const char TURRETS[] = "ressources/sound/turrets.ogg";

static const char *NAME_TOWERS[8] = {"ressources/towers/tower0.png",
                                    "ressources/towers/tower0_evo.png",
                                    "ressources/towers/tower1.png",
                                    "ressources/towers/tower1_evo.png",
                                    "ressources/towers/tower2.png",
                                    "ressources/towers/tower2_evo.png",
                                    "ressources/towers/tower3.png",
                                    "ressources/towers/tower3_evo.png"};

static const char *WRONG_PLACE[4] = {"ressources/towers/tower0_wrong.png",
                                    "ressources/towers/tower1_wrong.png",
                                    "ressources/towers/tower2_wrong.png",
                                    "ressources/towers/tower3_wrong.png"};

typedef struct castle_s {
    sfSprite *s_castle;
    sfTexture *t_castle;
    sfVector2f p_castle;
    sfSprite *s_end;
    sfTexture *t_end;
    sfSprite *s_heal;
    sfTexture *t_heal;
    sfVector2f p_heal;
    sfIntRect r_heal;
    int life;
} castle_t;

typedef struct turret_s {
    sfSprite *s_turret;
    sfTexture *t_turret;
    sfMusic *m_turret;
    sfMusic *m_canon;
    sfMusic *m_destroy;
    sfVector2f p_turret;
    int life;
    int damage;
    struct turret_s *next;
} turret_t;

#endif
