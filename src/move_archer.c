/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** move_archer.c
*/

#include "defender.h"

void increase_money(int add, money_t *money)
{
    static int gold = 0;

    gold += add;
    if (gold > 0) {
        money->gold += 1;
        gold -= 1;
    }
}

static void hit_dmg(archer_t *tmp, turret_t *turr, money_t *money)
{
    if ((sfClock_getElapsedTime(tmp->c_hit)).microseconds < 800000)
        return ;
    turr->life -= tmp->damage;
    tmp->life -= turr->damage;
    sfClock_restart(tmp->c_hit);
    if (turr->life <= 0) {
        sfMusic_play(turr->m_destroy);
        turr->p_turret.y = -1000.;
        sfSprite_setPosition(turr->s_turret, turr->p_turret);
    }
    if (tmp->life <= 0) {
        increase_money(100, money);
        sfMusic_play(tmp->m_death);
        tmp->p_archer.x = 0;
        tmp->p_archer.y = 0;
        sfSprite_setPosition(tmp->s_archer, tmp->p_archer);
    }
}

static int coll_castle(archer_t *tmp, inventory_t *inv, window_t w)
{
    sfFloatRect castle = sfSprite_getGlobalBounds(inv->castle.s_castle);
    sfFloatRect mob = sfSprite_getGlobalBounds(tmp->s_archer);

    if (sfFloatRect_intersects(&castle, &mob, NULL) == 1) {
        sfSprite_setTexture(tmp->s_archer, tmp->t_attack, sfTrue);
        sfSprite_setTextureRect(tmp->s_archer, tmp->r_attack);
        move_rect(tmp->c_attack, &tmp->r_attack, 210, 3150);
        hit_castle(tmp, &inv->castle, w, *inv);
        if (tmp->r_attack.left == 210)
            sfMusic_play(tmp->m_attack);
        return (0);
    }
    return (-1);
}

static int coll_turrets(archer_t *tmp, inventory_t *inv, window_t w)
{
    sfFloatRect tower = {0.0, 0.0, 0.0, 0.0};
    sfFloatRect mob = sfSprite_getGlobalBounds(tmp->s_archer);

    for (turret_t *turr = inv->turret; turr != NULL; turr = turr->next) {
        tower = sfSprite_getGlobalBounds(turr->s_turret);
        if (sfFloatRect_intersects(&tower, &mob, NULL) == 1) {
            sfSprite_setTexture(tmp->s_archer, tmp->t_attack, sfTrue);
            sfSprite_setTextureRect(tmp->s_archer, tmp->r_attack);
            move_rect(tmp->c_attack, &tmp->r_attack, 210, 3150);
            if (tmp->r_attack.left == 210)
                sfMusic_play(tmp->m_attack);
            if (tmp->r_attack.left == 1050)
                sfMusic_play((!turr->m_canon) ? turr->m_turret : turr->m_canon);
            hit_dmg(tmp, turr, &inv->money);
            return (0);
        }
    }
    return (coll_castle(tmp, inv, w));
}

void move_archers(archer_t **archer, inventory_t *inv, window_t w)
{
    for (archer_t *tmp = *archer; tmp != NULL; tmp = tmp->next) {
        if (coll_turrets(tmp, inv, w) == -1) {
            sfSprite_setTexture(tmp->s_archer, tmp->run_archer, 1);
            sfSprite_setTextureRect(tmp->s_archer, tmp->r_archer);
            move_rect(tmp->c_archer, &tmp->r_archer, 210, 3150);
            if ((sfClock_getElapsedTime(tmp->c_archer)).microseconds > 20000
                && tmp->p_archer.x != 0) {
                tmp->p_archer.x -= (2. * X_RES / 1366);
                tmp->p_archer.y += (1. * Y_RES / 768);
                sfSprite_setPosition(tmp->s_archer, tmp->p_archer);
            }
        }
    }
    increase_money(0, &inv->money);
    move_paladin(archer, inv, w);
}
