/*
** EPITECH PROJECT, 2024
** victory
** File description:
** victory
*/


int j;
int a;
#include <time.h>

#include "../../include/jam.h"

void move_rect2(sfVector2f *pos,sfIntRect *rect)
{
    if (pos->x > 500.0 && rect->top == 640) {
	rect->top = 0;
	rect->left = 0;
    }
    if (pos->x < 510) {
	if (rect->left < 550 && rect->top != 640) {
	    rect->left += 64;
	    pos->x += 5.5;
	}
	if (pos->x + 5.0 >= 500) {
	    rect->top = 640;
	    pos->x += 2.5;
	}
	rect->left = (rect->left < 128 && rect->top == 640) ? rect->left + 64 : rect->left;
	rect->left = (rect->left > 550 && rect->top != 640) ? 0 : rect->left;
    }
    if (rect->top < 1000 && pos->x >= 505) {
	rect->left = (rect->left < 420 && rect->top < 230) ? rect->left + 64 : rect->left;
	if (rect->left > 420 && rect->top < 230) {
	    rect->left = 0;
	    rect->top += 64;
	}
	rect->top = (rect->top > 230 && rect->top < 300) ? 832 : rect->top;
	if (rect->left < 360 && rect->top >= 500) { //832
	    rect->left += 64;
	}
	if (rect->left > 360 && rect->top >= 832) {
	    rect->left = 0;
	    rect->top += 64;
	}
    }
    if (rect->top > 1000)
	rect->top = 0;
}

int menu_event2(sfRenderWindow *window, sfEvent event, int *image_index)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        return 1;
    }
    return 0;
}

void function(sfRenderWindow *window, int *image_index, sfTexture *texture, \
	      sfSprite *sprite){
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 18);
    ptr->images[0] = "./src/Julci/images/img1.jpg";
    ptr->images[1] = "./src/Julci/images/img2.jpg";
    ptr->images[2] = "./src/Julci/images/img3.jpg";
    ptr->images[3] = "./src/Julci/images/img4.jpg";
    ptr->images[4] = "./src/Julci/images/img5.jpg";
    ptr->images[5] = "./src/Julci/images/img6.jpg";
    ptr->images[6] = "./src/Julci/images/img7.jpg";
    ptr->images[7] = "./src/Julci/images/img8.jpg";
    ptr->images[8] = "./src/Julci/images/img9.jpg";
    ptr->images[9] = "./src/Julci/images/img10.jpg";
    ptr->images[10] = "./src/Julci/images/img11.jpg";
    ptr->images[11] = "./src/Julci/images/img12.jpg";
    ptr->images[12] = "./src/Julci/images/img13.jpg";
    ptr->images[13] = "./src/Julci/images/img14.jpg";
    ptr->images[14] = "./src/Julci/images/img15.jpg";
    ptr->images[15] = "./src/Julci/images/img16.jpg";
    ptr->images[16] = "./src/Julci/images/Forest.jpg";
    ptr->images[17] = NULL;
    texture = sfTexture_createFromFile(ptr->images[*image_index], NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    if (*image_index != 15)
	*image_index = *image_index + 1;
    else {
	texture = sfTexture_createFromFile(ptr->images[16], NULL);
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_drawSprite(window, sprite, NULL);
	j = 1;
    }
}

void victory(sfRenderWindow* window)
{
    j = 0;
    int y = 0;
    sfVector2f pos1 = {0, 500}; // 500
    sfIntRect rect1 = {0, 704, 64, 64};
    sfIntRect rect = {0, 0, 1920, 1080};
    sfClock *clock = sfClock_create();
    sfTime time;
    int image_index = 0;
    sfVector2f scale = {7, 7}; // 4
    sfVector2f pos = {0, 20};
    sfSprite *sprite;
    float seconds;
    sfEvent event;
    sfTexture *texture;
    sfSprite *human = sfSprite_create();
    sfTexture *texture_h = sfTexture_createFromFile("./src/Julci/img/male.png", NULL);
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 4);
    sprite = sfSprite_create();
    ptr->images[0] = "./src/Julci/images/Forests.png";
    ptr->images[1] = "./src/Julci/images/defaite.png";
    texture = sfTexture_createFromFile("./src/Julci/images/Forest.jpg", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(human, texture_h, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 15); //12
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event2(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
	if (seconds > 0.0002 && y != 1) { 
	    function(window, &image_index,texture, sprite);
	    if (j == 1) {
		y = 1;
		sfSleep(sfMilliseconds(800));
		sfRenderWindow_drawSprite(window, sprite, NULL);
	    }
	    sfClock_restart(clock);
	}
	sfSleep(sfMilliseconds(10));
	if ( y == 1) {
	    sfRenderWindow_drawSprite(window, sprite, NULL);
	    move_rect2(&pos1, &rect1);
	    sfSprite_setPosition(human, pos1);
	    sfSprite_setTextureRect(human, rect1);
	    sfSprite_setScale(human, scale);
	    sfRenderWindow_drawSprite(window, human, NULL);
	}
        sfRenderWindow_display(window);
    }
}

/*int main(void)
{
    a = 1;
    sfRenderWindow* window;
    sfVideoMode mode = {1920, 1080};
    window = sfRenderWindow_create(mode, "defeat", sfResize | sfClose, NULL);
    if (a == 0)
	defeat(window);
    else
	victory(window);
}
*/