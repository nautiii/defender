/*
** EPITECH PROJECT, 2019
** defender
** File description:
** csfml.h
*/

#ifndef CSFML_H
#define CSFML_H

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>

void create_sprite(sfSprite **sprite, sfTexture *texture);
sfIntRect create_rect(int top, int left, int width, int height);
sfVector2f ret_size(sfTexture *texture);
sfVector2f create_vector2f(float x, float y);
sfVector2f ret_size(sfTexture *texture);
void close_event(sfRenderWindow *window);
sfRenderWindow *create_window(char **av, char *name);
void move_rect(sfClock *clock, sfIntRect *rect, int offset, int max);
void set_time(char time[6], int min, int sec);

#endif
