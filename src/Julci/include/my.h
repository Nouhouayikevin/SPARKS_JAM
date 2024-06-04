/*
** EPITECH PROJECT, 2024
** Header File
** File description:
** header file
*/

#ifndef MY_H_
    # define MY_H_

    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System/Clock.h>
    #include <stdio.h>
    #include <SFML/Audio.h>

    #define FILE sfTexture_createFromFile
    #define MOUSE menu->event.mouseButton
    #define CURSOR sfRenderWindow_setMouseCursorVisible
    #define WINDOW sfRenderWindow_create
typedef struct variables {
    sfSound *sound;
    sfSoundBuffer *musique;
    sfIntRect rect;
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfVector2f scale;
    sfVector2f scale_visor;
    sfSprite *nv;
    sfSprite *background;
    sfSprite *birds;
    sfSprite *cursor;
    sfTexture *t_birds;
    sfTexture *t_cursor;
    sfTexture *t_nv;
    sfTexture *t_background;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f pos;
    sfVector2f pos_c;
    sfVector2i position;
} data;
typedef struct menu {
    sfSound *sound;
    sfSoundBuffer *musique;
    sfIntRect rect;
    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfVector2f menu_scale;
    sfVector2f scale_pancarte;
    sfSprite *menu_s;
    sfSprite *dog;
    sfSprite *settings;
    sfSprite *viseur;
    sfSprite *pancarte;
    sfTexture *t_dog;
    sfTexture *t_settings;
    sfTexture *t_menu;
    sfTexture *t_viseur;
    sfTexture *t_pancarte;
    sfVector2f pos;
    sfVector2f pos_p;
} menu;
void disp_menu(menu *menu);
void init_menu(menu *menu);
void click(menu *menu);
void settings(menu *menu);
void settings_condition(menu *menu);
void close_boucle_menu(menu *menu);
void destroy(data *data);
void display(data *data);
void loop_contains(data *data, int i);
void game_loop(data *data);
void init_variables(data *data);
void kill(data *data, int i);
void move_rect(sfIntRect *rect);
void position(sfVector2f *pos);
void close_boucle(data *data);
void init_rect_and_mode(data *data);

#endif
