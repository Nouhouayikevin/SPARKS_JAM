/*
** EPITECH PROJECT, 2024
** parsing.c
** File description:
** This is my parsing main
*/
#include "my.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

platow_t *like_

main(int ac, char **av)
{
    char **map = NULL;
    char *str = NULL;
    struct stat h;
    platow_t *parse;
    int i = 0;
    int j = 0;

    if (ac == 2){
        stat(av[1], &h);
        if (open(av[1], O_RDONLY) == -1 || h.st_size == 0)
            return NULL;
        map = take_map(av, i, j);
    }
    if (map == NULL){
        parse = NULL;
        return parse;
    }
    parse = parsing(map, av, i, j);
    return parse;
}
