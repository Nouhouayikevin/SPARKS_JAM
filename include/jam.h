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

typedef struct combo {
    sfSprite *sprite;
    sfIntRect rect;
    sfTexture *texture;
    sfClock *clock;
    const char *song;
} combo_t;

//void display_menu(sfRenderWindow *window, int image_index);
void display_menu(sfRenderWindow *window, int image_index/*, sfTexture *texture, sfSprite *sprite*/);
int menu_event(sfRenderWindow *window, sfEvent event, int *image_index);
void menu(sfRenderWindow* window);
void init_menu();
void free_menu();
void launch_menu(sfRenderWindow *window);

/*____Protype__of___Kevin_____*/
typedef struct anim_s {
    sfVector2f vec;
    sfRectangleShape *R;
    sfSprite *key;
    sfTexture *T;
    sfIntRect rect;
    sfClock *c;
    sfEvent e;
    sfMusic *m;
} anim_t;

typedef struct all_anime {
    anim_t a;
    anim_t b;
    anim_t c;
    anim_t d;
    anim_t e;
    anim_t f;
} anime_t;
void cache_cache(sfRenderWindow *win);
void courir_chambre(sfRenderWindow *win);
void courir_couloir(sfRenderWindow *win);
void entree_dans_le_labyrinthe(sfRenderWindow *win);
void animation_phantom_vers_la_droite(anim_t *R, double timelaspe, sfClock *clock);
void poursuite1(sfRenderWindow *win);
double elapsed_time(sfClock *clock);
void hystory_debut(sfRenderWindow *window);
void events(anim_t *anim, sfRenderWindow * win);
void vu_du_tresor(sfRenderWindow *win);
void poursuite2(sfRenderWindow *win);
void move_rect_courir(sfIntRect *rect, int offset, int max_value);
void animation_courir_vers_gauche(anim_t *R, double timelaspe, sfClock *clock);
void explosion(anim_t *R, double timelaspe, sfClock *clock);


/*____Protype__of___Julci_____*/



/*____Protype__of___Joseph_____*/

typedef struct {
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} flame_t;

flame_t initialize_flame_struct(void);
flame_t pixels_flame(sfRenderWindow *window, flame_t f,
    sfVector2f pos);

/*____Protype__of___Renaud_____*/



/*____Protype__of___Tobi_____*/

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
affiche my_texture(void);
void draw_sprite(affiche key);
int launch_labyrinth(sfRenderWindow *window);

#endif /*___JAM___*/