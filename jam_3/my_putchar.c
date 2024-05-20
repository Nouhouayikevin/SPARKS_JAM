/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar file
*/
#include <unistd.h>
#include "my.h"
int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
