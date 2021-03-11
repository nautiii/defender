/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** set_money.c
*/

#include "defender.h"

static void fill_money(char *str, int nb)
{
    str[2] = (nb < 10) ? nb + '0' : (nb > 100000) ? nb / 100000 + '0' : str[2];
    str[2] = (nb >= 10 && nb < 100) ? nb / 10 + '0' : str[2];
    str[2] = (nb >= 100 && nb < 1000) ? nb / 100 + '0' : str[2];
    str[2] = (nb >= 1000 && nb < 10000) ? nb / 1000 + '0' : str[2];
    str[2] = (nb >= 10000 && nb < 100000) ? nb / 10000 + '0' : str[2];
    str[3] = (nb >= 10 && nb < 100) ? nb % 10 + '0' : str[3];
    str[3] = (nb >= 100 && nb < 1000) ? (nb / 10) % 10 + '0' : str[3];
    str[3] = (nb >= 1000 && nb < 10000) ? (nb / 100) % 10 + '0' : str[3];
    str[3] = (nb >= 10000 && nb < 100000) ? (nb / 1000) % 10 + '0' : str[3];
    str[3] = (nb > 100000) ? (nb / 10000) % 10 + '0' : str[3];
    str[4] = (nb >= 100 && nb < 1000) ? nb % 10 + '0' : str[4];
    str[4] = (nb >= 1000 && nb < 10000) ? (nb / 10) % 10 + '0' : str[4];
    str[4] = (nb >= 10000 && nb < 100000) ? (nb / 100) % 10 + '0' : str[4];
    str[4] = (nb > 100000) ? (nb / 1000) % 10 + '0' : str[4];
    str[5] = (nb >= 1000 && nb < 10000) ? nb % 10 + '0' : str[5];
    str[5] = (nb >= 10000 && nb < 100000) ? (nb / 10) % 10 + '0' : str[5];
    str[5] = (nb > 100000) ? (nb / 100) % 10 + '0' : str[5];
    str[6] = (nb >= 10000 && nb < 100000) ? nb % 10 + '0' : str[6];
    str[6] = (nb > 100000) ? (nb / 10) % 10 + '0' : str[6];
    str[7] = (nb > 100000) ? nb % 10 + '0' : str[7];
}

static void fill_score(score_t *score)
{
    if ((sfClock_getElapsedTime(score->c_score)).microseconds > 700000) {
        score->nb += 7;
        if (score->nb > 999999)
            score->nb = 999999;
        mitoa(score->nb, score->str_score);
        sfText_setString(score->txt_score, score->str_score);
        sfClock_restart(score->c_score);
    }
}

void reset_score_money(money_t *money, score_t *score)
{
    money->gold = (money->gold >= 999999) ? 999999 : money->gold;
    money->gold = (money->gold <= 0) ? 0 : money->gold;
    memset(&money->str_money, '\0', sizeof(money->str_money));
    money->str_money[0] = '$';
    money->str_money[1] = ':';
    fill_money(money->str_money, money->gold);
    fill_score(score);
    sfText_setString(money->txt_money, money->str_money);
}
