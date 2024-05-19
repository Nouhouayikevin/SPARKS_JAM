/*
** EPITECH PROJECT, 2024
** jam
** File description:
** jam
*/

#ifndef ___JAM___
#define ___JAM___
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*____Protype__of___Ramdon_____*/

typedef struct menu_s{
const char **images;
const char **flames;
}menu_t;

//void display_menu(sfRenderWindow *window, int image_index);
void display_menu(sfRenderWindow *window, int image_index, sfTexture *texture, sfSprite *sprite);
int menu_event(sfRenderWindow *window, sfEvent event, int *image_index);
void menu(sfRenderWindow* window);
void init_menu();
void free_menu();
void launch_menu(sfRenderWindow *window);

/*____Protype__of___Kevin_____*/



/*____Protype__of___Julci_____*/



/*____Protype__of___Joseph_____*/



/*____Protype__of___Renaud_____*/



/*____Protype__of___Tobi_____*/



#endif /*___JAM___*/