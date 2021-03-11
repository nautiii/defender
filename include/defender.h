/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** defender.h
*/

#ifndef DEFENDER_H
#define DEFENDER_H

#include "lib.h"
#include "map.h"
#include "menu.h"
#include "pause.h"
#include "enemy.h"
#include "cursor.h"
#include "building.h"
#include "inventory.h"

int X_RES;
int Y_RES;

int defender(char **av, int restart);
archer_t *init_archer(archer_t *arc);
int init_win(char **av, window_t *window);
void increase_money(int add, money_t *money);
int select_object(collis_t *c, inventory_t *inv);
void free_object(inventory_t *inv, archer_t **archer);
void move_archers(archer_t **archer, inventory_t *inv, window_t w);
void move_paladin(archer_t **archer, inventory_t *inv, window_t w);
void reset_score_money(money_t *money, score_t *score);
void algo_turret(turret_t **turret, int size, collis_t *c);
int add_tur(turret_t **t, collis_t *c, sfSprite *ca, int *gold);
void destroy_turret(turret_t *t, collis_t *cursor, money_t *money);
int check_superpos(inventory_t *inv, sfVector2f pos, collis_t *ca);
void free_interface(map_t *map, collis_t *cursor, pause_t pause[4]);
int pause_menu(map_t *map, collis_t *c, pause_t p[4], inventory_t inv);
int main_menu(window_t *window, collis_t *col, char **av, int restart);
archer_t *new_wave(archer_t **arc, map_t *map, button_t b, collis_t crs);
int check_castle(sfTexture *n, sfTexture *t, collis_t *ca, sfFloatRect c);
void display_window(map_t *m, inventory_t *inv, collis_t cur, archer_t *a);
void move_view(map_t *map, inventory_t *inv, pause_t pause[4], collis_t *curs);
int create_all(map_t *map, inventory_t *inv, pause_t pause[4], archer_t **arc);
int init_money(inventory_t *inv, sfFont *font);
void hit_castle(archer_t *tmp, castle_t *castle, window_t w, inventory_t inv);

#endif
