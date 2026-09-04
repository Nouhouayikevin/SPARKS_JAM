/*
** EPITECH PROJECT, 2024
** l'animation  du perso
** File description:
** a short animation
*/
#include "../../include/jam.h"

double elapsed_time(sfClock *clock)
{
    sfTime time;
    double seconds;

    time = sfClock_getElapsedTime(clock);
    return seconds = time.microseconds / 1000000.0;   
}

sfRenderWindow *init_win(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "my_radar", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 32);
    return window;
}

int get_time_elapsed(sfClock *clock)
{
    return (int)sfTime_asSeconds(sfClock_restart(clock));
}

void hystory_debut(sfRenderWindow *window, sfSound *song)
{
    anime_t image_font;
    image_font.a.c = sfClock_create();
    while (sfRenderWindow_isOpen(window)) {
        if (sfSound_getStatus(song) == sfStopped) {
        sfSound_play(song);
    }
        while (sfRenderWindow_pollEvent(window, &image_font.a.e)) {
            events(&image_font.a, window);
        }
        sfRenderWindow_clear(window, sfBlack);
            vu_du_tresor(window);
            poursuite1(window);
            poursuite2(window);
            cache_cache(window);
            courir_chambre(window);
            courir_couloir(window);
            entree_dans_le_labyrinthe(window);
        sfRenderWindow_display(window);
        break;
    }
    sfClock_destroy(image_font.a.c);
}

/*int main(void)
{
    sfRenderWindow *win = init_win();
    hystory_debut(win);
    sfRenderWindow_destroy((sfRenderWindow *)win);
    return 0;
}*/
