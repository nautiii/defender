/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** enemy.h
*/

#ifndef ENEMY_H
#define ENEMY_H

static const char ENEMY_RUN_DL[] = "ressources/enemy/run1.png";
static const char ENEMY_RUN_UR[] = "ressources/enemy/run2.png";
static const char ENEMY_RUN_DR[] = "ressources/enemy/run3.png";
static const char ENEMY_RUN_UL[] = "ressources/enemy/run4.png";
static const char ENEMY_ATT_UL[] = "ressources/enemy/attack_2.png";
static const char ENEMY_P_ATT[] = "ressources/enemy/pattack.png";
static const char ENEMY_P_RUN[] = "ressources/enemy/prun.png";
static const char SOUND_HIT[] = "ressources/sound/arrow.ogg";
static const char SOUND_SWORD[] = "ressources/sound/sword.ogg";
static const char SOUND_DEAD[] = "ressources/sound/dead.ogg";
static const char SOUND_DEADP[] = "ressources/sound/dead_paladin.ogg";
static const char END[] = "ressources/menu/end.png";

typedef struct archer_s {
    sfSprite *s_archer;
    sfTexture *run_archer;
    sfTexture *t_attack;
    sfClock *c_archer;
    sfClock *c_attack;
    sfClock *c_hit;
    sfMusic *m_attack;
    sfMusic *m_death;
    sfIntRect r_archer;
    sfIntRect r_attack;
    sfVector2f p_archer;
    int life;
    int lifepal;
    int damage;
    sfSprite *s_paladin;
    sfTexture *t_pattack;
    sfTexture *t_prun;
    sfMusic *m_sword;
    sfMusic *m_pdeath;
    sfClock *c_plac;
    sfClock *c_phit;
    sfIntRect r_pal;
    sfIntRect r_palatt;
    sfVector2f p_paladin;
    int dmgpal;
    struct archer_s *next;
} archer_t;

#endif
