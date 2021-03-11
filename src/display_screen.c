/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** display_screen.c
*/

#include "defender.h"

static void display_enemy(map_t m, archer_t *a)
{
    for (archer_t *archer = a; archer != NULL; archer = archer->next) {
        sfRenderWindow_drawSprite(m.window.window, archer->s_archer, NULL);
        sfRenderWindow_drawSprite(m.window.window, archer->s_paladin, NULL);
    }
}

static void display_map(map_t m, inventory_t inv, archer_t *a)
{
    sfRenderWindow_drawSprite(m.window.window, m.s_map, NULL);
    display_enemy(m, a);
    sfRenderWindow_drawSprite(m.window.window, inv.castle.s_castle, NULL);
    for (turret_t *turret = inv.turret; turret != NULL; turret = turret->next)
        sfRenderWindow_drawSprite(m.window.window, turret->s_turret, NULL);
    sfRenderWindow_drawSprite(m.window.window, m.mist.s_black, NULL);
    sfRenderWindow_drawSprite(m.window.window, m.mist.s_brm, NULL);
}

static void display_interface(map_t m, inventory_t inv)
{
    sfRenderWindow_drawSprite(m.window.window, inv.s_inventory, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.castle.s_heal, NULL);
    sfRenderWindow_drawSprite(m.window.window, m.chrono.s_chrono, NULL);
    sfRenderWindow_drawText(m.window.window, m.chrono.txt_chrono, NULL);
    sfRenderWindow_drawText(m.window.window, inv.score.txt_score, NULL);
    for (int a = 0; a != 8; a += 2)
        sfRenderWindow_drawSprite(m.window.window, inv.tower[a].s_tower, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.button[0].s_button, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.button[1].s_button, NULL);
}

static void display_cursor(collis_t cur, map_t m)
{
    if (cur.catch)
        sfRenderWindow_drawSprite(m.window.window, cur.catch, NULL);
    if (cur.s_destroy)
        sfRenderWindow_drawSprite(m.window.window, cur.s_destroy, NULL);
    else
        sfRenderWindow_drawSprite(m.window.window, cur.curspr, NULL);
}

void display_window(map_t *m, inventory_t *inv, collis_t cur, archer_t *a)
{
    sfClock *limit = sfClock_create();

    if (sfClock_getElapsedTime(inv->money.c_money).microseconds > 1000000) {
        increase_money(50, &inv->money);
        sfClock_restart(inv->money.c_money);
    }
    reset_score_money(&inv->money, &inv->score);
    while((sfClock_getElapsedTime(limit)).microseconds < 1000);
    sfRenderWindow_clear((*m).window.window, sfBlack);
    display_map(*m, *inv, a);
    display_interface(*m, *inv);
    display_cursor(cur, *m);
    sfRenderWindow_drawText((*m).window.window, (*inv).money.txt_money, NULL);
    sfRenderWindow_display((*m).window.window);
    sfClock_destroy(limit);
    if (m->window.restart == 1)
        m->window.restart = 0;
}
