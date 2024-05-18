/*
** EPITECH PROJECT, 2024
** menu
** File description:
** menu
*/
#include "../../include/jam.h"
int x;
int i;
int stop_animation = 0;

void flame_animation(sfRenderWindow **window, int flame_index)
{
    menu_t *ptr = malloc(sizeof(menu_t));
    sfTexture *texture;
    sfSprite *sprite;
    ptr->flames = malloc(sizeof(char *) * 19);
    
    ptr->flames[0] = "./pictures/flame1.png";
    ptr->flames[1] = "./pictures/flame2.png";
    ptr->flames[2] = "./pictures/flame3.png";
    ptr->flames[3] = "./pictures/flame4.png";
    ptr->flames[4] = "./pictures/flame5.png";
    ptr->flames[5] = "./pictures/flame6.png";
    ptr->flames[6] = "./pictures/flame7.png";
    ptr->flames[7] = "./pictures/flame8.png";
    ptr->flames[8] = "./pictures/flame9.png";
    ptr->flames[9] = "./pictures/flame10.png";
    ptr->flames[10] = "./pictures/flame11.png";
    ptr->flames[11] = "./pictures/flame12.png";
    ptr->flames[12] = "./pictures/flame13.png";
    ptr->flames[13] = "./pictures/flame14.png";
    ptr->flames[14] = "./pictures/flame15.png";
    ptr->flames[15] = "./pictures/flame16.png";
    ptr->flames[16] = "./pictures/flame17.png";
    ptr->flames[17] = "./pictures/flame18.png";
    ptr->flames[18] = NULL;

    texture = sfTexture_createFromFile(ptr->flames[flame_index], NULL);
    if (!texture) {
        printf("The texture failed to load\n");
        return;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(*window, sprite, NULL);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}

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

    if (image_index == 0) {
        for (int flame_index = 0; flame_index < 18; flame_index++) {
            flame_animation(&window, flame_index);
            sfRenderWindow_display(window);
            sfSleep(sfMilliseconds(100));
            if (stop_animation == 1) {
                stop_animation = 0;
                break;
            }
        }
    }
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
    stop_animation = 1;
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
            sfSleep(sfMilliseconds(1010));
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
