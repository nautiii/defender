/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** move_map.c
*/

#include "defender.h"

static void move_right(map_t *map, inventory_t *inv, pause_t p[4], int *o)
{
    if (!sfKeyboard_isKeyPressed(sfKeyD)
        || (sfView_getCenter(map->window.view)).x > (600.0 * X_RES / 720))
        return ;
    sfView_move(map->window.view, create_vector2f(6.0 * X_RES / 1920, 0));
    inv->p_inventory.x += 6.0 * X_RES / 1920;
    inv->money.p_money.x += 6.0 * X_RES / 1920;
    inv->score.p_score.x += 6.0 * X_RES / 1920;
    inv->castle.p_heal.x += 6.0 * X_RES / 1920;
    for (int a = 0; a != 8; a += 2)
        inv->tower[a].p_tower.x += 6.0 * X_RES / 1920;
    inv->button[0].p_button.x += 6.0 * X_RES / 1920;
    inv->button[1].p_button.x += 6.0 * X_RES / 1920;
    for (int a = 0; a != 4; a++)
        p[a].p_pause.x += 6.0 * X_RES / 1920;
    map->chrono.p_chrono.x += 6.0 * X_RES / 1920;
    map->chrono.txt_pos.x += 6.0 * X_RES / 1920;
    *o += 6.0 * X_RES / 1920;
}

static void move_left(map_t *map, inventory_t *inv, pause_t p[4], int *o)
{
    if (!sfKeyboard_isKeyPressed(sfKeyQ)
        || (sfView_getCenter(map->window.view)).x < (110.0 * X_RES / 720))
        return ;
    sfView_move(map->window.view, create_vector2f(-6.0 * X_RES / 1920, 0));
    inv->p_inventory.x -= 6.0 * X_RES / 1920;
    inv->money.p_money.x -= 6.0 * X_RES / 1920;
    inv->score.p_score.x -= 6.0 * X_RES / 1920;
    inv->castle.p_heal.x -= 6.0 * X_RES / 1920;
    for (int a = 0; a != 8; a += 2)
        inv->tower[a].p_tower.x -= 6.0 * X_RES / 1920;
    inv->button[0].p_button.x -= 6.0 * X_RES / 1920;
    inv->button[1].p_button.x -= 6.0 * X_RES / 1920;
    for (int a = 0; a != 4; a++)
        p[a].p_pause.x -= 6.0 * X_RES / 1920;
    map->chrono.p_chrono.x -= 6.0 * X_RES / 1920;
    map->chrono.txt_pos.x -= 6.0 * X_RES / 1920;
    *o -= 6.0 * X_RES / 1920;
}

static void move_up(map_t *map, inventory_t *inv, pause_t p[4], int *o)
{
    if (!sfKeyboard_isKeyPressed(sfKeyZ)
        || (sfView_getCenter(map->window.view)).y < (100.0 * Y_RES / 480))
        return ;
    sfView_move(map->window.view, create_vector2f(0, -6.0 * Y_RES / 1080));
    inv->p_inventory.y -= 6.0 * Y_RES / 1080;
    inv->money.p_money.y -= 6.0 * Y_RES / 1080;
    inv->score.p_score.y -= 6.0 * Y_RES / 1080;
    inv->castle.p_heal.y -= 6.0 * Y_RES / 1080;
    for (int a = 0; a != 8; a += 2)
        inv->tower[a].p_tower.y -= 6.0 * Y_RES / 1080;
    inv->button[0].p_button.y -= 6.0 * Y_RES / 1080;
    inv->button[1].p_button.y -= 6.0 * Y_RES / 1080;
    for (int a = 0; a != 4; a++)
        p[a].p_pause.y -= 6.0 * Y_RES / 1080;
    map->chrono.p_chrono.y -= 6.0 * Y_RES / 1080;
    map->chrono.txt_pos.y -= 6.0 * Y_RES / 1080;
    *o -= 6.0 * Y_RES / 1080;
}

static void move_down(map_t *map, inventory_t *inv, pause_t p[4], int *o)
{
    if (!sfKeyboard_isKeyPressed(sfKeyS)
        || (sfView_getCenter(map->window.view)).y > (350.0 * Y_RES / 480))
        return ;
    sfView_move(map->window.view, create_vector2f(0, 6.0 * Y_RES / 1080));
    inv->p_inventory.y += 6.0 * Y_RES / 1080;
    inv->money.p_money.y += 6.0 * Y_RES / 1080;
    inv->score.p_score.y += 6.0 * Y_RES / 1080;
    inv->castle.p_heal.y += 6.0 * Y_RES / 1080;
    for (int a = 0; a != 8; a += 2)
        inv->tower[a].p_tower.y += 6.0 * Y_RES / 1080;
    inv->button[0].p_button.y += 6.0 * Y_RES / 1080;
    inv->button[1].p_button.y += 6.0 * Y_RES / 1080;
    for (int a = 0; a != 4; a++)
        p[a].p_pause.y += 6.0 * Y_RES / 1080;
    map->chrono.p_chrono.y += 6.0 * Y_RES / 1080;
    map->chrono.txt_pos.y += 6.0 * Y_RES / 1080;
    *o += 6.0 * Y_RES / 1080;
}

void move_view(map_t *map, inventory_t *inv, pause_t pause[4], collis_t *c)
{
    move_right(map, inv, pause, &c->offset_x);
    move_left(map, inv, pause, &c->offset_x);
    move_up(map, inv, pause, &c->offset_y);
    move_down(map, inv, pause, &c->offset_y);
    sfRenderWindow_setView(map->window.window, map->window.view);
    sfSprite_setPosition(inv->s_inventory, inv->p_inventory);
    sfSprite_setPosition(inv->castle.s_heal, inv->castle.p_heal);
    sfSprite_setPosition(map->chrono.s_chrono, map->chrono.p_chrono);
    sfSprite_setPosition(inv->button[0].s_button, inv->button[0].p_button);
    sfSprite_setPosition(inv->button[1].s_button, inv->button[1].p_button);
    sfText_setPosition(map->chrono.txt_chrono, map->chrono.txt_pos);
    sfText_setPosition(inv->money.txt_money, inv->money.p_money);
    sfText_setPosition(inv->score.txt_score, inv->score.p_score);
    for (int a = 0; a != 4; a++)
        sfSprite_setPosition(pause[a].s_pause, pause[a].p_pause);
    for (int a = 0; a != 8; a += 2)
        sfSprite_setPosition(inv->tower[a].s_tower, inv->tower[a].p_tower);
}
