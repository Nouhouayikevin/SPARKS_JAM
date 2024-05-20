/*
** EPITECH PROJECT, 2024
** my_game_function3.c
** File description:
** This is for respect the coding style
*/
#include "my.h"
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>

sfIntRect my_bird(sfRenderWindow *w, sfSprite *sprite, affiche c, sfIntRect r)
{
    sfTime time;
    float seconds;
    sfVector2f corb_scale = {1.5, 1.5};

    time = sfClock_getElapsedTime(c.clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1){
        move_rect(&r, 155, 611 - 155);
        sfClock_restart(c.clock);
    }
    sfSprite_setScale(sprite, corb_scale);
    sfSprite_setTexture(sprite, c.texture, sfTrue);
    sfSprite_setTextureRect(sprite, r);
    sfRenderWindow_drawSprite(w, sprite, NULL);
    return r;
}

affiche *crow_caw(void)
{
    affiche *handler;

    handler = malloc(sizeof(affiche) * 2);
    handler[0].sound = sfSound_create();
    handler[0].soundbuffer = sfSoundBuffer_createFromFile("./crow_caw.ogg");
    sfSound_setBuffer(handler[0].sound, handler[0].soundbuffer);
    handler[1].sound = sfSound_create();
    handler[1].soundbuffer = sfSoundBuffer_createFromFile("./fire.ogg");
    sfSound_setBuffer(handler[1].sound, handler[1].soundbuffer);
    return handler;
}

int kill_event(sfRenderWindow *w, sfEvent e, sfVector2f *p, affiche *s)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(w);
    sfFloatRect bound = sfSprite_getGlobalBounds(s->sprite);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(w, mouse, NULL);

    while (sfRenderWindow_pollEvent(w, &e)){
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (e.type == sfEvtMouseButtonPressed &&
        sfFloatRect_contains(&bound, pos.x, pos.y)){
            s->count = s->count + 1;
            p->x = 0;
            p->y = random_num(500, 0);
            sfSound_play(s[1].sound);
        }
    }
    return s->count;
}

int game_function(sfEvent event, sfRenderWindow *window, sfVector2f scale)
{
    affiche corbeau = my_sprite(window, scale);
    sfIntRect rect = {0, 0, 155, 155};
    affiche back = background(window, scale);
    sfVector2f life_pos = {1700, 10};
    sfVector2f life_scale = {0.5, 0.5};
    affiche *l = life_sprite(window, life_pos, life_scale);
    sfVector2f sprite_pos = {-20, 10};
    affiche *sound = crow_caw();
    int x = 0;
    sound->sprite = corbeau.sprite;
    sound->count = 1;
    while (sfRenderWindow_isOpen(window)){
        sound->count = kill_event(window, event, &sprite_pos, sound);
        my_game_function(window, back, l, x);
        rect = my_bird(window, sound->sprite, corbeau, rect);
        sfSprite_setPosition(sound->sprite, sprite_pos);
        x = my_event(&sprite_pos, sound, x, window);
        sfRenderWindow_display(window);
    }
    destroy_resource_life(corbeau, l, sound);
}

int my_event(sfVector2f *s, affiche *sound, int x, sfRenderWindow *w)
{
    if (s->x == 0)
        sfSound_play(sound[0].sound);
    if (sound->count < 6)
        s->x += 1;
    if (sound->count >= 6 && sound->count < 20)
        s->x += 2;
    if (sound->count >= 20)
        s->x += 3;
    if (s->x >= 1919){
        if (x == 5) {
            game_restart(sound, w);
            x = -1;
            sound->count = 1;
        }
        if (x < 5)
            x++;
        s->x = 0;
        s->y = rand() % 500;
    }
    return x;
}
