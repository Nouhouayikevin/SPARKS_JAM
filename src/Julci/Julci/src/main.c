/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/my.h"

void usage(void)
{
    write(1, "USAGE\n    ./my_hunter \n\nDESCRIPTION\n", 36);
    write(1, "you must use your mouse to kill birds\n", 38);
}

int main(int ac, char **av)
{
    menu *menu = malloc(sizeof(struct menu));

    if (ac != 2 && ac != 1)
        return 84;
    if (ac == 2 && av[1][1] == 'h') {
        usage();
        return 0;
    } else if (ac == 2 && av[1][1] != 'h'){
        return 84;
    }
    disp_menu(menu);
    free(menu);
}
