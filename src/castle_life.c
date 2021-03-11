/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** castle_life.c
*/

#include "defender.h"

static void close_chib(sfRenderWindow *window, sfClock *limit)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
    sfClock_restart(limit);
}

void hit_castle(archer_t *tmp, castle_t *castle, window_t w, inventory_t inv)
{
    sfClock *limit = sfClock_create();

    if ((sfClock_getElapsedTime(tmp->c_archer)).microseconds < 40000)
        return ;
    castle->life -= tmp->damage;
    castle->r_heal.top = ((castle->life * 801) / 50000) - 801;
    sfSprite_setTextureRect(castle->s_heal, castle->r_heal);
    if (castle->life <= 0) {
        castle->t_end = sfTexture_createFromFile(END, NULL);
        create_sprite(&castle->s_end, castle->t_end);
        for (sfMusic_stop(w.loop); sfRenderWindow_isOpen(w.window); )
            if ((sfClock_getElapsedTime(limit)).microseconds > 1000) {
                close_chib(w.window, limit);
                sfRenderWindow_drawSprite(w.window, castle->s_end, NULL);
                sfRenderWindow_drawText(w.window, inv.score.txt_score, NULL);
                sfRenderWindow_drawText(w.window, inv.money.txt_money, NULL);
                sfRenderWindow_display(w.window);
            }
    }
}
