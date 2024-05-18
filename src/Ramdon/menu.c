/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include "../../include/jam.h"
int x;
int i;
void display_menu(sfRenderWindow *window, int image_index)
{
    sfTexture *texture;
    sfSprite *sprite;
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 4);

    ptr->images[0] = "./pictures/image1.png";
    ptr->images[1] = "./pictures/image2.png";
    ptr->images[2] = "./pictures/image3.png";
    ptr->images[3] = NULL;
    texture = sfTexture_createFromFile(ptr->images[image_index], NULL);
    if (!texture) {
        printf("The texture failed to load\n");
        return;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

int menu_event(sfRenderWindow *window, sfEvent event, int *image_index)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
	x = 1;
	i = 1;
        return 1;
    }
    return 0;
}

void menu(sfRenderWindow* window)
{
    sfEvent event;
    int image_index = 0;
    x = 0;
    i = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
	if (x == 0) {
            display_menu(window, image_index);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(1500));
            image_index = (image_index + 1) % 3;
	}
        else if (x == 1) {
	    display_menu(window, image_index);
	    sfRenderWindow_display(window);
	    image_index = (i == 1) ? (image_index + 1) % 3: image_index;
	}
	i = 0;
    }
}
