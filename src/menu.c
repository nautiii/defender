/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu.c
*/

#include "defender.h"

static int fill_menu(menu_t *menu, char const *filepath, int x, int y)
{
    float ratio_x = (X_RES / (1920 / 1080) / 2);
    float ratio_y = (Y_RES / (1920 / 1080) / 2);

    menu->t_menu = sfTexture_createFromFile(filepath, NULL);
    if (!menu->t_menu)
        return (-1);
    create_sprite(&menu->s_menu, menu->t_menu);
    menu->p_menu.x = ratio_x - ((ret_size(menu->t_menu)).x / 2) + x;
    menu->p_menu.y = ratio_y - ((ret_size(menu->t_menu)).y / 2) + y;
    sfSprite_setPosition(menu->s_menu, menu->p_menu);
    return (0);
}

static int init_menu(menu_t menu[8])
{
    float value = 40 * Y_RES / 1080;

    if ((fill_menu(&menu[0], MENU_BODY, 0, 0)
        | fill_menu(&menu[1], BUTT_PLAY, 0, -20 * Y_RES / 1080)
        | fill_menu(&menu[2], BUTT_OPT, -150 * X_RES / 1920, value)
        | fill_menu(&menu[3], BUTT_HELP, 150 * X_RES / 1920, value)
        | fill_menu(&menu[4], BUTT_QUIT, 0, value)
        | fill_menu(&menu[5], BUTT_SELECT, 0, -20 * Y_RES / 1080)
        | fill_menu(&menu[6], HELP, 0, 0)
        | fill_menu(&menu[7], OPTION, 0, 0)) == -1)
        return (-1);
    return (0);
}

static int display_menu(menu_t menu[6], collis_t *col, sfRenderWindow *window)
{
    for (int a = 0; a != 5; a++)
        sfRenderWindow_drawSprite(window, menu[a].s_menu, NULL);
    if (coll(window, col, menu) == 1)
        return (1);
    sfRenderWindow_drawSprite(window, col->curspr, NULL);
    sfRenderWindow_display(window);
    return (0);
}

static void set_game_start(window_t *w, collis_t *c, int restart)
{
    sfVector2f resize = {(X_RES - (600. * X_RES / 1920)) / 1920,
                        (Y_RES - (500. * X_RES / 1920)) / 1080};

    sfRenderWindow_setView(w->window, w->view);
    sfRenderWindow_setVerticalSyncEnabled(w->window, 1);
    w->restart = restart;
    sfSprite_setScale(c->curspr, resize);
    sfMusic_play(w->loop);
    sfMusic_setLoop(w->loop, 1);
}

int main_menu(window_t *w, collis_t *c, char **av, int restart)
{
    error_message_t *error = NULL;
    sfMusic *trump = sfMusic_createFromFile(TRUMPET);
    menu_t menu[8];

    change_resolution(av, w, 0);
    error = init_linked_list();
    if (!error || !trump || init_menu(menu) == -1 || mouse(w->window, c) == -1)
        return (-1);
    for (int index = 0; sfRenderWindow_isOpen(w->window); ) {
        mouse_pos(w->window, c);
        close_event(w->window);
        if (index == 0)
            print_message(w->window, error, &index, trump);
        if (display_menu(menu, c, w->window) == 1)
            break;
    }
    change_resolution(av, w, 1);
    free_error_message(&error, trump, menu);
    set_game_start(w, c, restart);
    return (0);
}
