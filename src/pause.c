/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** pause.c
*/

#include "defender.h"

static int pause_button(sfRenderWindow *win, pause_t pause[4], collis_t *cursor)
{
    sfFloatRect new = sfSprite_getGlobalBounds(pause[1].s_pause);
    sfFloatRect quit = sfSprite_getGlobalBounds(pause[2].s_pause);
    sfFloatRect cont = sfSprite_getGlobalBounds(pause[3].s_pause);
    sfFloatRect curs = sfSprite_getGlobalBounds(cursor->curspr);

    if (sfFloatRect_intersects(&new, &curs, NULL) == sfTrue
        && sfMouse_isButtonPressed(sfMouseLeft))
        return (2);
    if (sfFloatRect_intersects(&quit, &curs, NULL) == sfTrue
        && sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_close(win);
    if (sfFloatRect_intersects(&cont, &curs, NULL) == sfTrue
        && sfMouse_isButtonPressed(sfMouseLeft))
        return (1);
    return (0);
}

static void pause_disp(map_t m, inventory_t inv)
{
    sfRenderWindow_drawSprite(m.window.window, m.s_map, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.castle.s_castle, NULL);
    for (turret_t *turret = inv.turret; turret != NULL; turret = turret->next)
        sfRenderWindow_drawSprite(m.window.window, turret->s_turret, NULL);
    sfRenderWindow_drawSprite(m.window.window, m.mist.s_black, NULL);
    sfRenderWindow_drawSprite(m.window.window, m.mist.s_brm, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.s_inventory, NULL);
    for (int a = 0; a != 8; a += 2)
        sfRenderWindow_drawSprite(m.window.window, inv.tower[a].s_tower, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.button[0].s_button, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.button[1].s_button, NULL);
}

static void pause_display(map_t m, inventory_t inv, collis_t cur, pause_t p[4])
{
    sfRenderWindow_clear(m.window.window, sfBlack);
    pause_disp(m, inv);
    sfRenderWindow_drawSprite(m.window.window, m.chrono.s_chrono, NULL);
    sfRenderWindow_drawText(m.window.window, m.chrono.txt_chrono, NULL);
    sfRenderWindow_drawText(m.window.window, inv.score.txt_score, NULL);
    sfRenderWindow_drawText(m.window.window, inv.money.txt_money, NULL);
    sfRenderWindow_drawSprite(m.window.window, inv.castle.s_heal, NULL);
    for (int a = 0; a != 4; a++)
            sfRenderWindow_drawSprite(m.window.window, p[a].s_pause, NULL);
    sfRenderWindow_drawSprite(m.window.window, cur.curspr, NULL);
    sfRenderWindow_display(m.window.window);
}

static int pause_actions(map_t *map, collis_t *c, pause_t p[4], inventory_t i)
{
    int a = 0;

    while (sfRenderWindow_isOpen(map->window.window)) {
        mouse_pos(map->window.window, c);
        close_event(map->window.window);
        a = pause_button(map->window.window, p, c);
        if (a == 1)
            break;
        else if (a == 2) {
            sfRenderWindow_close(map->window.window);
            return (0);
        }
        pause_display(*map, i, *c, p);
    }
    return (-1);
}

int pause_menu(map_t *map, collis_t *c, pause_t p[4], inventory_t inv)
{
    if (!sfKeyboard_isKeyPressed(sfKeyEscape))
        return (-1);
    return (pause_actions(map, c, p, inv));
}
