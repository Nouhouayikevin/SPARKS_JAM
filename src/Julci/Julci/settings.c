/*
** EPITECH PROJECT, 2024
** settings
** File description:
** settings
*/

#include "../../include/jam.h"

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

void draw_text(sfRenderWindow *window, char *string, sfVector2f position, int size)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("font/Serenata Vantages Regular.ttf");
    
    text = sfText_create();
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size); //35
    sfText_setPosition(text, position);
    sfText_setColor(text, (sfColor)sfColor_fromRGB(173, 255, 47)); //rgb(240,128,128)
    //rgb(205,92,92)
    //rgb(220,20,60)
    //rgb(139,0,0)

    sfRenderWindow_drawText(window, text, NULL);
}

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

void settings(sfRenderWindow* window)
{
    int image_index = 0;
    sfVector2f scale = {0.7, 0.7};
    sfVector2f settings = {780, 200};//800
    sfVector2f pos = {250, 20};
    sfSprite *sprite;
    sfTexture *texture;
    sfTime time;
    float seconds;
    sfClock *clock = sfClock_create();
    sfEvent event;

    texture = sfTexture_createFromFile("images/settings.png", NULL);
    
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        sfRenderWindow_drawSprite(window, sprite, NULL);
	draw_text(window, "Settings", settings, 80); //45
        /*if (seconds > 0.10) {
            move_rect(&rect);
            position(&pos);
            
            sfSprite_setTextureRect(sprite, rect);
            
            sfRenderWindow_drawSprite(window, sprite, NULL);
            z++;
            sfClock_restart(clock);
	    }*/
        //sfSleep(sfMilliseconds(380));
        sfRenderWindow_display(window);
    }
}

int main(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1920, 1080};
    window = sfRenderWindow_create(mode, "settings", sfResize | sfClose, NULL);
    settings(window);
}
