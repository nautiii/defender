/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** drag_and_drop.c
*/

#include "defender.h"

static void chose_tower(collis_t *c, inventory_t *inv)
{
    sfFloatRect rect = {.0, .0, .0, .0};
    sfFloatRect curs = sfSprite_getGlobalBounds(c->curspr);

    for (int a = 6; a != -2; a -= 2) {
        rect = sfSprite_getGlobalBounds(inv->tower[a].s_tower);
        if (sfFloatRect_intersects(&rect, &curs, NULL) == 1) {
            create_sprite(&c->catch, inv->tower[a].t_tower);
            sfSprite_setOrigin(c->catch, ret_size(inv->tower[a].t_tower));
            c->type = a;
            c->price = (a > 0) ? (a - 1) * 1000 : a * 1000;
            c->price += (a < 4) ? 500 : 0;
        }
    }
    rect = sfSprite_getGlobalBounds(inv->button[1].s_button);
    if (sfFloatRect_intersects(&rect, &curs, NULL) == 1)
        create_sprite(&c->s_destroy, c->t_destroy);
}

static int move_selection(collis_t *c)
{
    if (c->catch)
        sfSprite_setPosition(c->catch, (sfVector2f){c->x, c->y});
    if (c->s_destroy) {
        sfSprite_setPosition(c->s_destroy, (sfVector2f){c->x, c->y});
        return (0);
    }
    return (-1);
}

static void evolve_turret(collis_t *c, turret_t *turret, money_t *money)
{
    sfFloatRect rect = {.0, .0, .0, .0};
    sfFloatRect curs = sfSprite_getGlobalBounds(c->curspr);
    turret_t *tmp = turret;

    for ( ; tmp != NULL; tmp = tmp->next) {
        rect = sfSprite_getGlobalBounds(tmp->s_turret);
        if (sfFloatRect_intersects(&rect, &curs, NULL) == 1) {
            if ((tmp->life * 5) > money->gold)
                return ;
            sfSprite_setTexture(tmp->s_turret, tmp->t_turret, 1);
            tmp->life *= 2;
            tmp->damage *= 2;
            money->gold -= (tmp->life * 5);
        }
    }
}

int select_object(collis_t *c, inventory_t *i)
{
    int b;

    if (sfMouse_isButtonPressed(sfMouseLeft))
        chose_tower(c, i);
    if (sfMouse_isButtonPressed(sfMouseRight))
        evolve_turret(c, i->turret, &i->money);
    if (move_selection(c) == 0)
        destroy_turret(i->turret, c, &i->money);
    b = check_superpos(i, create_vector2f(c->x, c->y), c);
    if (!sfMouse_isButtonPressed(sfMouseLeft) && c->catch) {
        if (b != 0)
            return (add_tur(&i->turret, c, i->castle.s_castle, &i->money.gold));
        sfSprite_destroy(c->catch);
        c->catch = NULL;
    }
    return (0);
}
