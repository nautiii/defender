/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** turret_position.c
*/

#include "defender.h"

static void swap_info(turret_t **turret)
{
    int life1 = (*turret)->life, life2 = (*turret)->next->life;
    int damage1 = (*turret)->damage;
    int damage2 = (*turret)->next->damage;
    sfSprite *sprite1 = (*turret)->s_turret;
    sfSprite *sprite2 = (*turret)->next->s_turret;
    sfTexture *texture1 = (*turret)->t_turret;
    sfTexture *texture2 = (*turret)->next->t_turret;
    sfVector2f position1 = (*turret)->p_turret;
    sfVector2f position2 = (*turret)->next->p_turret;

    (*turret)->s_turret = sprite2;
    (*turret)->t_turret = texture2;
    (*turret)->p_turret = position2;
    (*turret)->damage = damage2;
    (*turret)->life = life2;
    (*turret)->next->s_turret = sprite1;
    (*turret)->next->t_turret = texture1;
    (*turret)->next->p_turret = position1;
    (*turret)->next->damage = damage1;
    (*turret)->next->life = life1;
}

void algo_turret(turret_t **turret, int size, collis_t *c)
{
    turret_t *first = *turret;
    turret_t *check = NULL;
    int a = 0;

    while (a != size - 1) {
        for ( ; (*turret)->next != NULL; *turret = (*turret)->next)
            if ((*turret)->p_turret.y > (*turret)->next->p_turret.y)
                swap_info(turret);
        *turret = first;
        check = *turret;
        for (a = 0; check->next != NULL; a++, check = check->next)
            if (check->p_turret.y > check->next->p_turret.y)
                break;
    }
    sfSprite_destroy(c->catch);
    c->catch = NULL;
}

int check_castle(sfTexture *n, sfTexture *t, collis_t *ca, sfFloatRect c)
{
    sfFloatRect catch = sfSprite_getGlobalBounds(ca->catch);

    if (sfFloatRect_intersects(&catch, &c, NULL) == 1) {
        sfSprite_setTexture(ca->catch, n, 1);
        return (0);
    }
    sfSprite_setTexture(ca->catch, t, 1);
    return (-1);
}

int check_superpos(inventory_t *inv, sfVector2f pos, collis_t *ca)
{
    sfTexture *nop = NULL;
    sfTexture *towers = NULL;
    sfFloatRect castle = sfSprite_getGlobalBounds(inv->castle.s_castle);

    if (!ca->catch)
        return (-1);
    if (ca->price > inv->money.gold)
        return (0);
    nop = sfTexture_createFromFile(WRONG_PLACE[ca->type / 2], NULL);
    towers = sfTexture_createFromFile(NAME_TOWERS[ca->type], NULL);
    for (turret_t *check = inv->turret; check != NULL; check = check->next) {
        if (check->p_turret.x - pos.x < 70.0 * X_RES / 1920 &&
            check->p_turret.x - pos.x > -70.0 * X_RES / 1920 &&
            check->p_turret.y - pos.y < 38.0 * Y_RES / 1080 &&
            check->p_turret.y - pos.y > -38.0 * Y_RES / 1080) {
            sfSprite_setTexture(ca->catch, nop, 1);
            return (0);
        }
    }
    return (check_castle(nop, towers, ca, castle));
}
