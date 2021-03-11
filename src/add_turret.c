/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** add_turret.c
*/

#include "defender.h"

static int fill_new(turret_t *new, collis_t *c)
{
    new->s_turret = sfSprite_copy(c->catch);
    new->p_turret = create_vector2f(c->x, c->y);
    sfSprite_setPosition(new->s_turret, new->p_turret);
    new->life = (c->type + 1) * 100;
    new->damage = (c->type + 1) * 8;
    new->m_turret = sfMusic_createFromFile(TURRETS);
    new->m_destroy = sfMusic_createFromFile(SOUND_DEL);
    if (new->life == 700) {
        if (!(new->m_canon = sfMusic_createFromFile(CANON)))
            return (-1);
    } else
        new->m_canon = NULL;
    new->t_turret = sfTexture_createFromFile(NAME_TOWERS[c->type + 1], NULL);
    if (!new->t_turret || !new->m_turret || !new->m_destroy)
        return (-1);
    return (0);
}

int add_tur(turret_t **t, collis_t *c, sfSprite *ca, int *gold)
{
    turret_t *new = malloc(sizeof(*new));
    int z = 0;

    if (!new)
        return (-1);
    if (fill_new(new, c) == -1)
        return (-1);
    new->next = *t;
    *t = new;
    for (turret_t *size = *t; size != NULL; size = size->next, z++);
    algo_turret(t, z, c);
    *gold -= c->price;
    c->price = 0;
    return (0);
}
