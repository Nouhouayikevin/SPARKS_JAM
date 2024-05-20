/*
** EPITECH PROJECT, 2024
** my_strcmp.c
** File description:
** This file is for string comparison
*/
#include <stdio.h>
#include <string.h>
#include "my.h"
int my_strglen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        i++;
        str++;
    }
    return i;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j;

    if (my_strglen(s1) > my_strglen(s2))
        j = my_strglen(s1);
    else
        j = my_strglen(s2);
    while (i < j){
        if (s1[i] > s2[i])
            return 1;
        if (s2[i] > s1[i])
            return -1;
        i++;
    }
    return 0;
}
