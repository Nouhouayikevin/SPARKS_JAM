/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <time.h>
    #include <SFML/Audio.h>
    #include <stdio.h>
    #include <string.h>

typedef struct my_struct {

    sfTime time;
    char *str;
    float seconds;
    sfClock *clock;
    sfEvent event;
    sfVector2f bird_position;
    sfVector2f kill_bird;
    sfVector2f fire_position;
    sfVector2i mouse;
    sfMusic *beat;
    sfVideoMode mode;
    sfTexture *fire_sprite;
    sfSprite *explosion;
    sfTexture *cursor;
    sfSprite *curs;
    sfTexture *game;
    sfSprite * sprite_game;
    sfSoundBuffer* gun;
    sfSound* gun_sound;
    sfRenderWindow *win;
    sfMouseButtonEvent Button;
    sfIntRect *rect;
    int offset;
    int max_value;
}new_struct;

typedef struct player {
    sfVector2f mouve;
    sfTexture *p_texture;
    sfSprite *player;
    sfClock *clock;
    sfTime time;
    float seconds ;
} player;


int my_putstr(char const *src);
void my_putchar(char c);
int my_put_nbr(int nb);
void manage_mouse_click(sfMouseButtonEvent Button);
void move_rect(sfIntRect *rect, int offset, int max_value);
void end_of_programm(new_struct *vamos);
void set_of_elements(new_struct *vamos);
int error_case(new_struct *vamos);
void naissance_elements(new_struct *vamos);
void usage_game(new_struct *vamos);
void create_sprite(new_struct *hunter);
void creator(new_struct *hunter);
void begining_of_events(new_struct *hunter);
void analyse_events(new_struct *hunter);
void conditon_of_reapparition(new_struct *hunter);
int my_putstr(char const *str);

sfIntRect player_func(sfIntRect rect, player *gamer);
#endif
