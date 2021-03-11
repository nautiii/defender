/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defender.c
*/

#include "defender.h"

static int events(map_t *map, inventory_t *inv, collis_t *cursor, pause_t p[4])
{
    if (!map->chrono.c_chrono)
        map->chrono.c_chrono = sfClock_create();
    close_event(map->window.window);
    mouse_pos(map->window.window, cursor);
    move_view(map, inv, p, cursor);
    select_object(cursor, inv);
    if (pause_menu(map, cursor, p, *inv) == 0) {
        sfMusic_stop(map->window.loop);
        return (0);
    }
    return (-1);
}

int defender(char **av, int restart)
{
    map_t map;
    collis_t cursor;
    inventory_t inv;
    archer_t *arc = NULL;
    pause_t pause[4];

    if ((init_win(av, &map.window) | create_all(&map, &inv, pause, &arc)) == -1)
        return (-1);
    if (main_menu(&map.window, &cursor, av, restart) == -1)
        return (-1);
    while (sfRenderWindow_isOpen(map.window.window)) {
        (events(&map, &inv, &cursor, pause) == 0) ? defender(av, 1) : 0;
        if (!(arc = new_wave(&arc, &map, inv.button[0], cursor)) && arc)
            return (-1);
        move_archers(&arc, &inv, map.window);
        display_window(&map, &inv, cursor, arc);
    }
    free_interface(&map, &cursor, pause);
    free_object(&inv, &arc);
    return (0);
}
