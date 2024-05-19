/*
** EPITECH PROJECT, 2024
** victory
** File description:
** victory
*/

#include "../../include/jam.h"
int z;

sfSound *sound()
{
    sfSound *sound;
    sfSoundBuffer *musique;
    sound = sfSound_create();
    musique = sfSoundBuffer_createFromFile("musique/song2.ogg");
    sfSound_setBuffer(sound, musique);
    sfSound_play(sound);
    return sound;
}

void move_rect(sfIntRect *rect)
{
    if (rect->left < 220) {
        rect->left = rect->left + 100;
    } else
        rect->left = 0;
}

void position(sfVector2f *pos)
{
    if (pos->x < 1920 && pos->y < 920 * 4) {
        pos->x += 50;
        pos->y += (z % 2) ? -1 * 50 : 70;
    } else {
        pos->x = 0;
        pos->y += (z % 2) ? -20 : 50;
        pos->y = (pos->y >= 400) ? 70 + 1 : pos->y;
    }
}
/*
{
    sfSprite *sprite;
    sfTexture *texture;
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 9);
    ptr->images[0] = "./'treasure chest'/'treasure chest0000.png'";
    ptr->images[1] = "./'treasure chest'/'treasure chest0001.png'";
    ptr->images[2] = "./'treasure chest'/'treasure chest0002.png'";
    ptr->images[3] = "./'treasure chest'/'treasure chest0003.png'";
    ptr->images[4] = "./'treasure chest'/'treasure chest0004.png'";
    ptr->images[5] = "./'treasure chest'/'treasure chest0005.png'";
    ptr->images[6] = "./'treasure chest'/'treasure chest0006.png'";
    ptr->images[7] = "./'treasure chest'/'treasure chest0007.png'";
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
    }*/

int menu_event(sfRenderWindow *window, sfEvent event, int *image_index)
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
    ptr->images = malloc(sizeof(char *) * 9);
    ptr->images[0] = "images/img1.jpg";
    ptr->images[1] = "images/img001.jpg";
    //ptr->images[2] = "images/img2.jpg";
    ptr->images[2] = "images/img3.jpg";
    ptr->images[3] = "images/img4.jpg";
    ptr->images[4] = "images/img5.jpg";
    ptr->images[5] = "images/img6.jpg";
    ptr->images[6] = NULL;
    texture = sfTexture_createFromFile(ptr->images[*image_index], NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    if (*image_index != 5)
    *image_index = *image_index + 1;
}

void victory(sfRenderWindow* window)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {0, 20};
    sfSprite *sprite;
    sfSprite *sprite1;
    sfSprite *lose;
    sfSprite *crane;
    sfTexture *texture;
    sfTime time;
    float seconds;
    sfTexture *texture1;
    sfClock *clock = sfClock_create();
    sfEvent event;
    sfIntRect rect = {5, 5, 97, 150};
    int image_index = 0;
    menu_t *ptr = malloc(sizeof(menu_t));
    ptr->images = malloc(sizeof(char *) * 4);

    //ptr->images[0] = "images/victory.png";
    //ptr->images[1] = "images/defaite.png";
    
    /*texture = sfTexture_createFromFile(ptr->images[0], NULL);
      texture1 = sfTexture_createFromFile(ptr->images[1], NULL);*/
    sprite = sfSprite_create();
    sprite1 = sfSprite_create();
    lose = sfSprite_create();
    crane = sfSprite_create();
    //sfSprite_setTexture(sprite, texture, sfTrue);
    //sfSprite_setTexture(sprite1, texture1, sfTrue);
    /*texture1 = sfTexture_createFromFile("images/crâne.png", NULL);
    sfSprite_setTexture(crane, texture1, sfTrue);
    texture1 = sfTexture_createFromFile("images/you_lose.jpeg", NULL);
    sfSprite_setTexture(lose, texture1, sfTrue);
    //sfSound *song = sound();*/
    
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
	//sfSprite_setScale(sprite,  (sfVector2f){0.9, 0.9});
        //sfRenderWindow_drawSprite(window, sprite, NULL);
        /*sfSprite_setPosition(lose,  (sfVector2f){640, 500});
        
        sfRenderWindow_drawSprite(window, lose, NULL);
        sfRenderWindow_drawSprite(window, crane, NULL);*/
        if (seconds > 0.00015) {
	    function(window, &image_index,texture, sprite);
	    sfSleep(sfMilliseconds(350));
            //move_rect(&rect);
            //position(&pos);
	    //sfSprite_setPosition(sprite, pos);
            //sfSprite_setTextureRect(sprite, rect);
            //sfSprite_setScale(sprite, scale);
            //sfRenderWindow_drawSprite(window, sprite, NULL);
            z++;
            sfClock_restart(clock);
        }
        
	  sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1920, 1080};
    window = sfRenderWindow_create(mode, "victory", sfResize | sfClose, NULL);
    victory(window);
}
