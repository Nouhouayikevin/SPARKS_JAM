/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** This is my header
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdbool.h>
#ifndef MY_H
    #define MY_H
typedef struct sprite_text {
    sfSoundBuffer* soundbuffer;
    sfSound* sound;
    sfIntRect rect;
    sfVideoMode mode;
    sfClock *clock;
    sfVector2f scale;
    sfFont* font;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mouse;
    int *x;
    double count;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *button_text;
    sfSprite *sprite2;
    sfText* text;
}affiche;
typedef struct collide {
    sfRectangleShape *rect;
}rect_t;
typedef struct {
    sfIntRect rect;
    sfVector2f pos;
    sfVector2f scale;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f outline_size;
    sfRectangleShape *outline;
    int collide;
} move_player_t;
move_player_t event_handler(sfEvent e, sfRenderWindow *w, sfVector2f sc, move_player_t p, rect_t *rectangle);
int rect_col(sfRectangleShape *rect2, sfVector2f pos, sfVector2f pos_size);
int in_collide(rect_t *rectangle, move_player_t p, int x, int y);
move_player_t init_move_player_t_struct(move_player_t player);
move_player_t cut_player_move(move_player_t p, sfEvent event, rect_t *rectangle);
void set_and_draw_player(move_player_t p, sfRenderWindow *window);
void destroy_player_val(move_player_t p);
rect_t *my_rectangle(rect_t *rectangle);
affiche background(sfRenderWindow *window, sfVector2f scale);
affiche my_texture(move_player_t p);
void draw_sprite(affiche key);
int my_putchar(char c);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
void usage(void);
int game_function(sfEvent event, sfRenderWindow *window, sfVector2f scale);
extern bool is_movable;
#endif
