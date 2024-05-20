/*
** EPITECH PROJECT, 2024
** Day04
** File description:
** This is a file
*/
#include <stdio.h>
#include "my.h"
int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        i++;
        str++;
    }
    return i;
}
