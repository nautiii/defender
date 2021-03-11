/*
** EPITECH PROJECT, 2019
** defender
** File description:
** error_messages.c
*/

#include "defender.h"

static int fill_link(error_message_t **new)
{
    int a = -15;
    int x = X_RES;
    int y = Y_RES;

    (*new)->t_error = sfTexture_createFromFile(ERR_MESSAGE, NULL);
    (*new)->m_error = sfMusic_createFromFile(MUSIC_MENU);
    if (!(*new)->t_error || !(*new)->m_error)
        return (-1);
    create_sprite(&(*new)->s_error, (*new)->t_error);
    (*new)->p_error = create_vector2f((rand() * a) % x, (rand() * a) % y);
    sfSprite_setPosition((*new)->s_error, (*new)->p_error);
    return (0);
}

error_message_t *init_linked_list(void)
{
    error_message_t *newlist = NULL;
    error_message_t *list = NULL;

    for (int i = 0; i != NB_ERROR_MESS; i++) {
        newlist = malloc(sizeof(*newlist));
        if (!newlist)
            return (NULL);
        if (fill_link(&newlist) == -1)
            return (NULL);
        newlist->next = list;
        list = newlist;
    }
    return (newlist);
}

void free_error_message(error_message_t **error, sfMusic *tr, menu_t menu[8])
{
    error_message_t *delete = NULL;

    while (*error != NULL) {
        sfMusic_destroy((*error)->m_error);
        sfSprite_destroy((*error)->s_error);
        sfTexture_destroy((*error)->t_error);
        delete = *error;
        *error = (*error)->next;
        free(delete);
    }
    sfMusic_destroy(tr);
    for (int a = 0; a != 8; a++) {
        sfSprite_destroy(menu[a].s_menu);
        sfTexture_destroy(menu[a].t_menu);
    }
}

void print_message(sfRenderWindow *w, error_message_t *err, int *i, sfMusic *t)
{
    sfClock *c_error = sfClock_create();

    for ( ; err != NULL; err = err->next, sfClock_restart(c_error)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            break;
        while ((sfClock_getElapsedTime(c_error)).microseconds < 40000);
        sfMusic_play(err->m_error);
        sfRenderWindow_drawSprite(w, err->s_error, NULL);
        sfRenderWindow_display(w);
    }
    while ((sfClock_getElapsedTime(c_error)).microseconds < 1000000);
    sfClock_destroy(c_error);
    sfMusic_play(t);
    *i += 1;
}
