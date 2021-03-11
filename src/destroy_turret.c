/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** destroy_turret.c
*/

#include "defender.h"

static void algo_delete(turret_t *tmp)
{
    turret_t *suppr = NULL;

    suppr = tmp->next;
    tmp->next = tmp->next->next;
    sfSprite_destroy(suppr->s_turret);
    sfTexture_destroy(suppr->t_turret);
    free(suppr);
}

void destroy_turret(turret_t *t, collis_t *cursor, money_t *money)
{
    sfFloatRect rect, curs = sfSprite_getGlobalBounds(cursor->s_destroy);

    if (!sfMouse_isButtonPressed(sfMouseLeft)
        || (sfClock_getElapsedTime(cursor->c_destroy)).microseconds < 100000)
        return ;
    sfSprite_destroy(cursor->s_destroy);
    cursor->s_destroy = NULL;
    sfClock_restart(cursor->c_destroy);
    if (!t)
        return ;
    for (turret_t *tmp = t; tmp->next != NULL; tmp = tmp->next) {
        rect = sfSprite_getGlobalBounds(tmp->next->s_turret);
        if (sfFloatRect_intersects(&rect, &curs, NULL) == 1) {
            increase_money(tmp->life, money);
            sfMusic_play(cursor->m_destroy);
            algo_delete(tmp);
            break;
        }
    }
}
