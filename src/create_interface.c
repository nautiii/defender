/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** create_all.c
*/

#include "defender.h"

int init_win(char **av, window_t *window)
{
    sfFloatRect size = {0.0, 0.0, X_RES, Y_RES};

    window->window = create_window(av, "defender");
    if (!window->window)
        return (-1);
    window->view = sfView_createFromRect(size);
    window->loop = sfMusic_createFromFile(MUSIC_LOOP);
    if (!window->loop)
        return (-1);
    return (0);
}

int init_pause(pause_t pause[4])
{
    sfVector2f vector = {860 * X_RES / 1920, 210 * Y_RES / 1080};
    int position = 0;

    for (int a = 0; a != 4; a++) {
        pause[a].t_pause = sfTexture_createFromFile(PAUSE[a], NULL);
        if (!pause[a].t_pause)
            return (-1);
        create_sprite(&pause[a].s_pause, pause[a].t_pause);
        pause[a].p_pause = create_vector2f(vector.x, vector.y + position);
        sfSprite_setPosition(pause[a].s_pause, pause[a].p_pause);
        position += 200 * Y_RES / 1920;
    }
    pause[0].p_pause = create_vector2f(420 * X_RES / 1920, 100 * Y_RES / 1080);
    sfSprite_setPosition(pause[0].s_pause, pause[0].p_pause);
    return (0);
}

int init_map(map_t *map)
{
    map->t_map = sfTexture_createFromFile(MAP_GROUND, NULL);
    map->mist.t_brm = sfTexture_createFromFile(MIST, NULL);
    map->mist.t_black = sfTexture_createFromFile(BLACK_ZONE, NULL);
    if (!map->t_map || !map->mist.t_brm || !map->mist.t_black)
        return (-1);
    map->p_map = create_vector2f(0, 0);
    map->mist.p_brm.x = -660 * X_RES / 1920;
    map->mist.p_brm.y = -530 * Y_RES / 1080;
    create_sprite(&map->s_map, map->t_map);
    create_sprite(&map->mist.s_black, map->mist.t_black);
    create_sprite(&map->mist.s_brm, map->mist.t_brm);
    sfSprite_setPosition(map->s_map, map->p_map);
    sfSprite_setPosition(map->mist.s_brm, map->mist.p_brm);
    sfSprite_setPosition(map->mist.s_black, map->mist.p_brm);
    return (0);
}

int init_buttons(button_t button[2])
{
    sfVector2f vector1 = {1737 * X_RES / 1920, 150 * Y_RES / 1080};
    sfVector2f vector2 = {1739 * X_RES / 1920, 883 * Y_RES / 1080};
    sfVector2f scale = {.29 * X_RES / 720, .29 * Y_RES / 480};

    button[0].t_button = sfTexture_createFromFile(SKIP, NULL);
    button[1].t_button = sfTexture_createFromFile(DELETE, NULL);
    if (!button[0].t_button || !button[1].t_button)
        return (-1);
    create_sprite(&button[0].s_button, button[0].t_button);
    create_sprite(&button[1].s_button, button[1].t_button);
    sfSprite_setScale(button[0].s_button, scale);
    sfSprite_setScale(button[1].s_button, scale);
    button[0].p_button = vector1;
    button[1].p_button = vector2;
    sfSprite_setPosition(button[0].s_button, button[0].p_button);
    sfSprite_setPosition(button[1].s_button, button[1].p_button);
    return (0);
}

int init_money(inventory_t *inv, sfFont *font)
{
    float x = 1.8 * X_RES / 1920;
    float y = 1.8 * Y_RES / 1080;

    inv->money.gold = 10000;
    inv->money.c_money = sfClock_create();
    inv->money.txt_money = sfText_create();
    inv->money.p_money = create_vector2f(0, 0);
    reset_score_money(&inv->money, &inv->score);
    sfText_setFont(inv->money.txt_money, font);
    sfText_setColor(inv->money.txt_money, sfYellow);
    sfText_setScale(inv->money.txt_money, create_vector2f(x, y));
}
