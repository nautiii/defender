/*
** EPITECH PROJECT, 2019
** defender
** File description:
** lib.h
*/

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "csfml.h"

void mputstr(char const *s);
int mstrcmp(char const *s1, char const *s2);
int mgetnbr(char const *s);
void mitoa(long int nb, char s[13]);

#endif
