/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** free_all.c
*/

#include "defender.h"

static void free_turrets(turret_t **turret)
{
    turret_t *delete = NULL;

    while (*turret != NULL) {
        delete = *turret;
        *turret = (*turret)->next;
        sfSprite_destroy(delete->s_turret);
        sfTexture_destroy(delete->t_turret);
        sfMusic_destroy(delete->m_turret);
        sfMusic_destroy(delete->m_destroy);
        if (!delete->m_canon)
            sfMusic_destroy(delete->m_canon);
        free(delete);
    }
}

static void free_enemies(archer_t **archer)
{
    archer_t *delete = NULL;

    while (*archer != NULL) {
        delete = *archer;
        *archer = (*archer)->next;
        sfSprite_destroy(delete->s_archer);
        sfSprite_destroy(delete->s_paladin);
        sfTexture_destroy(delete->run_archer);
        sfTexture_destroy(delete->t_attack);
        sfTexture_destroy(delete->t_pattack);
        sfTexture_destroy(delete->t_prun);
        sfClock_destroy(delete->c_archer);
        sfClock_destroy(delete->c_attack);
        sfClock_destroy(delete->c_plac);
        sfMusic_destroy(delete->m_attack);
        sfMusic_destroy(delete->m_death);
        sfMusic_destroy(delete->m_sword);
        sfMusic_destroy(delete->m_pdeath);
        free(delete);
    }
}

void free_object(inventory_t *inv, archer_t **archer)
{
    sfSprite_destroy(inv->s_inventory);
    sfTexture_destroy(inv->t_inventory);
    sfSprite_destroy(inv->castle.s_castle);
    sfTexture_destroy(inv->castle.t_castle);
    sfText_destroy(inv->score.txt_score);
    sfClock_destroy(inv->score.c_score);
    sfText_destroy(inv->money.txt_money);
    sfSprite_destroy(inv->button[0].s_button);
    sfTexture_destroy(inv->button[0].t_button);
    sfSprite_destroy(inv->button[1].s_button);
    sfTexture_destroy(inv->button[1].t_button);
    for (int a = 0; a != 8; a++) {
        sfSprite_destroy(inv->tower[a].s_tower);
        sfTexture_destroy(inv->tower[a].t_tower);
    }
    free_turrets(&inv->turret);
    free_enemies(archer);
}

static void free_map(map_t *map)
{
    sfRenderWindow_destroy(map->window.window);
    sfView_destroy(map->window.view);
    sfMusic_destroy(map->window.loop);
    sfSprite_destroy(map->s_map);
    sfTexture_destroy(map->t_map);
    sfSprite_destroy(map->mist.s_brm);
    sfSprite_destroy(map->mist.s_black);
    sfTexture_destroy(map->mist.t_brm);
    sfTexture_destroy(map->mist.t_black);
}

void free_interface(map_t *map, collis_t *cursor, pause_t pause[4])
{
    free_map(map);
    sfSprite_destroy(map->chrono.s_chrono);
    sfTexture_destroy(map->chrono.t_chrono);
    sfClock_destroy(map->chrono.c_chrono);
    sfText_destroy(map->chrono.txt_chrono);
    sfFont_destroy(map->chrono.f_chrono);
    sfTexture_destroy(cursor->curstex);
    sfSprite_destroy(cursor->curspr);
    sfMusic_destroy(cursor->m_destroy);
    if (cursor->catch)
        sfSprite_destroy(cursor->catch);
    if (cursor->s_destroy)
        sfSprite_destroy(cursor->s_destroy);
    sfTexture_destroy(cursor->t_destroy);
    sfClock_destroy(cursor->c_destroy);
    for (int a = 0; a != 4; a++) {
        sfSprite_destroy(pause[a].s_pause);
        sfTexture_destroy(pause[a].t_pause);
    }
}
