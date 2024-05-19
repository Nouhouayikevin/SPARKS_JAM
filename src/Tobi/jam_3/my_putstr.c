/*
** EPITECH PROJECT, 2024
** This is a file
** File description:
** File to constr char
*/
#include <stdio.h>
#include <unistd.h>
#include "my.h"
int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str++;
    }
}
