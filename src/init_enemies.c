/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** init_enemies.c
*/

#include "defender.h"

static int create_from_files(archer_t *arc)
{
    arc->t_pattack = sfTexture_createFromFile(ENEMY_P_ATT, NULL);
    arc->t_prun = sfTexture_createFromFile(ENEMY_P_RUN, NULL);
    arc->m_sword = sfMusic_createFromFile(SOUND_SWORD);
    arc->m_pdeath = sfMusic_createFromFile(SOUND_DEADP);
    if (!arc->t_pattack || !arc->t_prun || !arc->m_sword || !arc->m_pdeath)
        return (-1);
    return (0);
}

static archer_t *init_paladin(archer_t *arc)
{
    int a = ((800 * X_RES / 1920) - (600 * X_RES / 1920));
    int b = ((200 * Y_RES / 1080) - (20 * Y_RES / 1080));
    int x = (rand() / (double)RAND_MAX) * a + 100 * X_RES / 1920;
    int y = (rand() / (double)RAND_MAX) * b + 10 * Y_RES / 1080;

    if (create_from_files(arc) == -1)
        return (NULL);
    create_sprite(&arc->s_paladin, arc->t_prun);
    arc->p_paladin = create_vector2f(x, y);
    arc->r_pal = create_rect(0, 0, 60, 79);
    arc->r_palatt = create_rect(0, 0, 70, 71);
    arc->c_plac = sfClock_create();
    arc->c_phit = sfClock_create();
    sfSprite_setTextureRect(arc->s_paladin, arc->r_pal);
    sfSprite_setPosition(arc->s_paladin, arc->p_paladin);
    arc->lifepal = 200;
    arc->dmgpal = 4;
    return (arc);
}

static archer_t *create_ressources(archer_t *arc)
{
    if (!arc)
        return (NULL);
    arc->run_archer = sfTexture_createFromFile(ENEMY_RUN_UR, NULL);
    arc->t_attack = sfTexture_createFromFile(ENEMY_ATT_UL, NULL);
    arc->m_attack = sfMusic_createFromFile(SOUND_HIT);
    arc->m_death = sfMusic_createFromFile(SOUND_DEAD);
    if (!arc->run_archer || !arc->t_attack || !arc->m_attack || !arc->m_death)
        return (NULL);
    return (arc);
}

archer_t *init_archer(archer_t *arc)
{
    int a = ((1800 * X_RES / 1920) - (1600 * X_RES / 1920));
    int b = ((200 * Y_RES / 1080) - (40 * Y_RES / 1080));
    int x = (rand() / (double)RAND_MAX) * a + 1500 * X_RES / 1920;
    int y = (rand() / (double)RAND_MAX) * b + 50 * Y_RES / 1080;

    arc = malloc(sizeof(*arc));
    if (!(arc = create_ressources(arc)))
        return (NULL);
    create_sprite(&arc->s_archer, arc->run_archer);
    arc->p_archer = create_vector2f(x, y);
    arc->r_archer = create_rect(0, 0, 210, 210);
    arc->r_attack = create_rect(0, 0, 210, 210);
    arc->c_attack = sfClock_create();
    arc->c_archer = sfClock_create();
    arc->c_hit = sfClock_create();
    arc->life = 100;
    arc->damage = 2;
    sfSprite_setTextureRect(arc->s_archer, arc->r_archer);
    sfSprite_setPosition(arc->s_archer, arc->p_archer);
    return (init_paladin(arc));
}
