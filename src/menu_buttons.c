/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** menu_buttons.c
*/

#include "defender.h"

static int click_play(sfRenderWindow *window, menu_t menu[6], int x, int y)
{
    float ratio_x = (X_RES / (1920 / 1080) / 2);
    float ratio_y = (Y_RES / (1920 / 1080) / 2);

    menu[5].p_menu.x = ratio_x - ((ret_size(menu[0].t_menu)).x / 2) + x;
    menu[5].p_menu.y = ratio_y - ((ret_size(menu[0].t_menu)).y / 2) + y;
    sfSprite_setPosition(menu[5].s_menu, menu[5].p_menu);
    sfRenderWindow_drawSprite(window, menu[5].s_menu, NULL);
    return (sfMouse_isButtonPressed(sfMouseLeft)) ? (1) : (0);
}

static int click_opt(sfRenderWindow *window, menu_t menu[6], int x, int y)
{
    float ratio_x = (X_RES / (1920 / 1080) / 2);
    float ratio_y = (Y_RES / (1920 / 1080) / 2);

    menu[5].p_menu.x = ratio_x - ((ret_size(menu[0].t_menu)).x / 2) + x;
    menu[5].p_menu.y = ratio_y - ((ret_size(menu[0].t_menu)).y / 2) + y;
    sfSprite_setPosition(menu[5].s_menu, menu[5].p_menu);
    sfRenderWindow_drawSprite(window, menu[5].s_menu, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRenderWindow_drawSprite(window, menu[7].s_menu, NULL);
    }
    return (0);
}

static int click_help(sfRenderWindow *window, menu_t menu[8], int x, int y)
{
    float ratio_x = (X_RES / (1920 / 1080) / 2);
    float ratio_y = (Y_RES / (1920 / 1080) / 2);

    menu[5].p_menu.x = ratio_x - ((ret_size(menu[0].t_menu)).x / 2) + x;
    menu[5].p_menu.y = ratio_y - ((ret_size(menu[0].t_menu)).y / 2) + y;
    sfSprite_setPosition(menu[5].s_menu, menu[5].p_menu);
    sfRenderWindow_drawSprite(window, menu[5].s_menu, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_drawSprite(window, menu[6].s_menu, NULL);
    return (0);
}

static int click_quit(sfRenderWindow *window, menu_t menu[6], int x, int y)
{
    float ratio_x = (X_RES / (1920 / 1080) / 2);
    float ratio_y = (Y_RES / (1920 / 1080) / 2);

    menu[5].p_menu.x = ratio_x - ((ret_size(menu[0].t_menu)).x / 2) + x;
    menu[5].p_menu.y = ratio_y - ((ret_size(menu[0].t_menu)).y / 2) + y;
    sfSprite_setPosition(menu[5].s_menu, menu[5].p_menu);
    sfRenderWindow_drawSprite(window, menu[5].s_menu, NULL);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_close(window);
    return (0);
}

int coll(sfRenderWindow *w, collis_t *col, menu_t menu[6])
{
    sfFloatRect play = sfSprite_getGlobalBounds(menu[1].s_menu);
    sfFloatRect opt = sfSprite_getGlobalBounds(menu[2].s_menu);
    sfFloatRect help = sfSprite_getGlobalBounds(menu[3].s_menu);
    sfFloatRect quit = sfSprite_getGlobalBounds(menu[4].s_menu);
    sfFloatRect mouse = sfSprite_getGlobalBounds(col->curspr);

    if (sfFloatRect_intersects(&play, &mouse, NULL) == sfTrue)
        return (click_play(w, menu, 268 * X_RES / 1920, 54 * Y_RES / 1080));
    if (sfFloatRect_intersects(&opt, &mouse, NULL) == sfTrue)
        return (click_opt(w, menu, 118 * X_RES / 1920, 114 * Y_RES / 1080));
    if (sfFloatRect_intersects(&quit, &mouse, NULL) == sfTrue)
        return (click_quit(w, menu, 267 * X_RES / 1920, 114 * Y_RES / 1080));
    if (sfFloatRect_intersects(&help, &mouse, NULL) == sfTrue)
        return (click_help(w, menu, 417 * X_RES / 1920, 114 * Y_RES / 1080));
    return (0);
}
