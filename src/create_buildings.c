/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** init_objects.c
*/

#include "defender.h"

static int init_castle(castle_t *castle, inventory_t *inv, sfFont *font)
{
    init_money(inv, font);
    castle->life = 50000;
    castle->t_heal = sfTexture_createFromFile(HEALTH_BAR, NULL);
    castle->t_castle = sfTexture_createFromFile(CASTLE, NULL);
    if (!castle->t_castle || !castle->t_heal)
        return (-1);
    create_sprite(&castle->s_heal, castle->t_heal);
    create_sprite(&castle->s_castle, castle->t_castle);
    castle->p_heal = create_vector2f(1840 * X_RES / 1920, 140 * Y_RES / 1080);
    castle->p_castle = create_vector2f(870 * X_RES / 1920, 400 * Y_RES / 1080);
    sfSprite_setPosition(castle->s_castle, castle->p_castle);
    sfSprite_setPosition(castle->s_heal, castle->p_heal);
    castle->r_heal = create_rect(0, 0, 34, 801);
    sfSprite_setTextureRect(castle->s_heal, castle->r_heal);
    return (0);
}

static int init_towers(tower_t tower[8])
{
    sfVector2f vector = {1730 * X_RES / 1920, 443 * Y_RES / 1080};
    sfVector2f scale = {.29 * X_RES / 720, .29 * Y_RES / 480};

    for (int a = 0; a != 8; a++) {
        tower[a].t_tower = sfTexture_createFromFile(NAME_TOWERS[a], NULL);
        if (!tower[a].t_tower)
            return (-1);
        create_sprite(&tower[a].s_tower, tower[a].t_tower);
        sfSprite_setScale(tower[a].s_tower, scale);
    }
    for (int a = 0, pos = 0; a != 8; a += 2, pos += 200 * Y_RES / 1920) {
        tower[a].p_tower = create_vector2f(vector.x, vector.y + pos);
        sfSprite_setPosition(tower[a].s_tower, tower[a].p_tower);
    }
    return (0);
}

static int init_chrono(chrono_t *chrono)
{
    float x_scale = 0.3 * X_RES / 720;
    float y_scale = 0.3 * Y_RES / 480;

    chrono->txt_pos = create_vector2f(1726 * X_RES / 1920, 400 * Y_RES / 1080);
    create_sprite(&chrono->s_chrono, chrono->t_chrono);
    chrono->p_chrono = create_vector2f(1728 * X_RES / 1920, 230 * Y_RES / 1080);
    chrono->secondes = 0;
    chrono->minutes = 2;
    if (!(chrono->f_chrono = sfFont_createFromFile(FONT)))
        return (-1);
    memset(&chrono->time, '\0', sizeof(chrono->time));
    set_time(chrono->time, chrono->minutes, chrono->secondes);
    chrono->time[2] = ':';
    chrono->c_chrono = NULL;
    chrono->txt_chrono = sfText_create();
    sfText_setString(chrono->txt_chrono, chrono->time);
    sfText_setFont(chrono->txt_chrono, chrono->f_chrono);
    sfText_setPosition(chrono->txt_chrono, chrono->txt_pos);
    sfText_setScale(chrono->txt_chrono, create_vector2f(x_scale, y_scale));
    return (0);
}

static int init_score(score_t *score, chrono_t chrono)
{
    char *tmp = "score:";
    float x = 1.4 * X_RES / 1920;
    float y = 1.4 * Y_RES / 1080;

    score->nb = 0;
    score->txt_score = sfText_create();
    memset(&score->str_score, '\0', sizeof(score->str_score));
    for (int a = 0; tmp[a] != '\0'; a++)
        score->str_score[a] = tmp[a];
    for (int a = 6; a != 12; a++)
        score->str_score[a] = '0';
    sfText_setString(score->txt_score, score->str_score);
    sfText_setFont(score->txt_score, chrono.f_chrono);
    score->p_score = create_vector2f(0, 60 * Y_RES / 1080);
    sfText_setPosition(score->txt_score, score->p_score);
    sfText_setScale(score->txt_score, create_vector2f(x, y));
    sfText_setColor(score->txt_score, (sfColor){180, 210, 250, 255});
    score->c_score = sfClock_create();
    return (0);
}

int create_all(map_t *map, inventory_t *inv, pause_t pause[4], archer_t **arc)
{
    map->chrono.time_limit = 1000000;
    map->chrono.r_chrono = create_rect(0, 0, 70, 149);
    map->chrono.t_chrono = sfTexture_createFromFile(LOAD, NULL);
    inv->t_inventory = sfTexture_createFromFile(INVENTORY, NULL);
    if (!inv->t_inventory || !map->chrono.t_chrono)
        return (-1);
    inv->p_inventory = create_vector2f(1640 * X_RES / 1920, 0);
    create_sprite(&inv->s_inventory, inv->t_inventory);
    sfSprite_setPosition(inv->s_inventory, inv->p_inventory);
    inv->turret = NULL;
    if ((init_towers(inv->tower) | init_pause(pause) | init_map(map)
        | init_chrono(&map->chrono) | init_buttons(inv->button)
        | init_score(&inv->score, map->chrono)) == -1)
        return (-1);
    sfSprite_setTextureRect(map->chrono.s_chrono, map->chrono.r_chrono);
    sfSprite_setPosition(map->chrono.s_chrono, map->chrono.p_chrono);
    return (init_castle(&inv->castle, inv, map->chrono.f_chrono));
}
