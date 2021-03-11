/*
** EPITECH PROJECT, 2019
** defender
** File description:
** menu.h
*/

#ifndef MENU_H
#define MENU_H

#include "csfml.h"

static const char MUSIC_MENU[] = "ressources/sound/error_sound.ogg";
static const char TRUMPET[] = "ressources/sound/trumpet.ogg";
static const char ERR_MESSAGE[] = "ressources/menu/Error_message.png";
static const char MENU_BODY[] = "ressources/menu/menu_body.png";
static const char BUTT_PLAY[] = "ressources/menu/bouton_play.png";
static const char BUTT_OPT[] = "ressources/menu/bouton_options.png";
static const char BUTT_HELP[] = "ressources/menu/bouton_help.png";
static const char BUTT_QUIT[] = "ressources/menu/bouton_quit.png";
static const char BUTT_SELECT[] = "ressources/menu/bouton_select.png";
static const char HELP[] = "ressources/menu/helpi.png";
static const char OPTION[] = "ressources/menu/optioni.png";

#define NB_ERROR_MESS (75)

typedef struct error_message_s {
    sfSprite *s_error;
    sfTexture *t_error;
    sfVector2f p_error;
    sfMusic *m_error;
    struct error_message_s *next;
} error_message_t;

typedef struct menu_s {
    sfSprite *s_menu;
    sfTexture *t_menu;
    sfVector2f p_menu;
} menu_t;

error_message_t *init_linked_list(void);
void free_error_message(error_message_t **error, sfMusic *tr, menu_t menu[8]);
void print_message(sfRenderWindow *w, error_message_t *err, int *i, sfMusic *t);

#endif
