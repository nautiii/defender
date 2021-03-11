/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pladian
*/

#include "defender.h"

static void pal_dmg(archer_t *tmp, turret_t *turr, money_t *money)
{
    if ((sfClock_getElapsedTime(tmp->c_phit)).microseconds < 900000)
        return ;
    turr->life -= tmp->dmgpal;
    tmp->lifepal -= turr->damage;
    sfClock_restart(tmp->c_phit);
    if (turr->life <= 0) {
        sfMusic_play(turr->m_destroy);
        turr->p_turret.y = -1000.;
        sfSprite_setPosition(turr->s_turret, turr->p_turret);
    }
    if (tmp->lifepal <= 0) {
        increase_money(500, money);
        sfMusic_play(tmp->m_pdeath);
        tmp->p_paladin.x = -100;
        sfSprite_setPosition(tmp->s_paladin, tmp->p_paladin);
    }
}

static int pal_castle(archer_t *tmp, inventory_t *inv, window_t w)
{
    sfFloatRect castle = sfSprite_getGlobalBounds(inv->castle.s_castle);
    sfFloatRect mob = sfSprite_getGlobalBounds(tmp->s_paladin);

    if (sfFloatRect_intersects(&castle, &mob, NULL) == 1) {
        sfSprite_setTexture(tmp->s_paladin, tmp->t_pattack, sfTrue);
        sfSprite_setTextureRect(tmp->s_paladin, tmp->r_palatt);
        move_rect(tmp->c_plac, &tmp->r_palatt, 70, 1120);
        hit_castle(tmp, &inv->castle, w, *inv);
        if (tmp->r_palatt.left == 70)
            sfMusic_play(tmp->m_sword);
        return (0);
    }
    return (-1);
}

static int pal_turrets(archer_t *tmp, inventory_t *inv, window_t w)
{
    sfFloatRect tower = {0.0, 0.0, 0.0, 0.0};
    sfFloatRect mob = sfSprite_getGlobalBounds(tmp->s_paladin);

    for (turret_t *turr = inv->turret; turr != NULL; turr = turr->next) {
        tower = sfSprite_getGlobalBounds(turr->s_turret);
        if (sfFloatRect_intersects(&tower, &mob, NULL) == 1) {
            sfSprite_setTexture(tmp->s_paladin, tmp->t_pattack, sfTrue);
            sfSprite_setTextureRect(tmp->s_paladin, tmp->r_palatt);
            move_rect(tmp->c_plac, &tmp->r_palatt, 70, 1120);
            if (tmp->r_palatt.left == 70)
                sfMusic_play(tmp->m_sword);
            if (tmp->r_palatt.left == 350)
                sfMusic_play((!turr->m_canon) ? turr->m_turret : turr->m_canon);
            pal_dmg(tmp, turr, &inv->money);
            return (0);
        }
    }
    return (pal_castle(tmp, inv, w));
}

void move_paladin(archer_t **archer, inventory_t *inv, window_t w)
{
    for (archer_t *tmp = *archer; tmp != NULL; tmp = tmp->next) {
        if (pal_turrets(tmp, inv, w) == -1) {
            sfSprite_setTexture(tmp->s_paladin, tmp->t_prun, 1);
            sfSprite_setTextureRect(tmp->s_paladin, tmp->r_pal);
            move_rect(tmp->c_plac, &tmp->r_pal, 70, 1050);
            if ((sfClock_getElapsedTime(tmp->c_archer)).microseconds > 20000
                && tmp->p_paladin.x != -100) {
                tmp->p_paladin.x += (1. * X_RES / 1366);
                tmp->p_paladin.y += (0.5 * Y_RES / 768);
                sfSprite_setPosition(tmp->s_paladin, tmp->p_paladin);
            }
        }
    }
    increase_money(0, &inv->money);
}
