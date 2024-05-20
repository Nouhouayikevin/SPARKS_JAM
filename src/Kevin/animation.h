/*
** EPITECH PROJECT, 2024
** animation.h
** File description:
** of the man
*/

#ifndef __A__
    #define __A__
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <math.h>
    #include <signal.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <time.h>
    #include <math.h>
    #include <SFML/Audio.h>

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
#endif