/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** enemy_waves.c
*/

#include "defender.h"

static void modify_time(button_t button, collis_t crs, int *time)
{
    sfFloatRect cursor = sfSprite_getGlobalBounds(crs.curspr);
    sfFloatRect button_rect = sfSprite_getGlobalBounds(button.s_button);

    if (sfMouse_isButtonPressed(sfMouseLeft)
        && sfFloatRect_intersects(&cursor, &button_rect, NULL) == 1)
        *time = 10000;
    else
        *time = 1000000;
}

static void wave_chrono(chrono_t *c, archer_t **arc, button_t bu, collis_t crs)
{
    modify_time(bu, crs, &c->time_limit);
    if ((sfClock_getElapsedTime(c->c_chrono)).microseconds >= c->time_limit) {
        if (c->secondes == 0) {
            c->secondes = (c->minutes != 0) ? 59 : 0;
            c->minutes = (c->minutes != 0) ? c->minutes - 1 : 2;
        } else
            c->secondes -= 1;
        set_time(c->time, c->minutes, c->secondes);
        sfText_setString(c->txt_chrono, c->time);
        sfClock_restart(c->c_chrono);
        if (c->secondes == 20 || c->secondes == 40
            || (c->secondes == 0 && c->minutes != 0))
            c->r_chrono.left += 70;
        if (c->secondes == 0 && c->minutes == 2)
            c->r_chrono.left = 0;
        sfSprite_setTextureRect(c->s_chrono, c->r_chrono);
    }
}

static void restart_values(int *nb_enemy, int *save, int *check, int *time)
{
    *nb_enemy = 5;
    *save = 5;
    *check = 0;
    *time = 1000000;
}

archer_t *new_wave(archer_t **arc, map_t *map, button_t b, collis_t crs)
{
    archer_t *new = NULL, *list = *arc;
    static int nb_enemy = 5;
    static int save = 5;
    static int check = 0;

    if (map->window.restart == 1)
        restart_values(&nb_enemy, &save, &check, &map->chrono.time_limit);
    wave_chrono(&map->chrono, arc, b, crs);
    if (map->chrono.secondes == 0 && map->chrono.minutes == 0 && check == 0)
        save = nb_enemy = save * 1.1;
    check = (map->chrono.secondes == 0 && map->chrono.minutes == 0) ? 1 : 0;
    if (nb_enemy == 0)
        return (*arc);
    if (!(new = init_archer(new)))
        return (NULL);
    new->next = list;
    list = new;
    nb_enemy--;
    return (new);
}
