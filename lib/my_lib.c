/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_lib.c
*/

#include "lib.h"

void mputstr(char const *s)
{
    for (int i = 0; s[i] != 0; i++)
        write(1, &s[i], 1);
}

int mgetnbr(char const *s)
{
    int nb = 0;
    int i = 0;

    if (s[0] == '-')
        i += 1;
    for ( ; s[i] != 0; i++) {
        if (!(s[i] >= 48 && s[i] <= 57))
            break;
        nb = nb * 10 + s[i] - 48;
    }
    if (s[0] == '-')
        return (-nb);
    return (nb);
}

void mitoa(long int nb, char s[13])
{
    short a;

    for (a = 11; nb > 0 && a != 6; a--) {
        s[a] = (nb % 10) + 48;
        nb /= 10;
    }
    s[a] = nb + 48;
}

int mstrcmp(char const *s1, char const *s2)
{
    int i;

    if (!s1 || !s2)
        return (-1);
    for (i = 0; s1[i] != 0; i++)
        if (s1[i] != s2[i])
            return (-1);
    return (s1[i] != s2[i]) ? (-1) : (0);
}
