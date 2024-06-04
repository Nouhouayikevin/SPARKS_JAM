/*
** EPITECH PROJECT, 2024
** menu.c
** File description:
** menu.c
*/

#include "../include/my.h"

void settings_condition(menu *menu)
{
    close_boucle_menu(menu);
    if (menu->event.type == sfEvtMouseButtonPressed
        && MOUSE.x >= 877 && MOUSE.x <= 965 &&
        MOUSE.y >= 480 && MOUSE.y <= 545) {
        sfSound_pause(menu->sound);
    }
    if (menu->event.type == sfEvtMouseButtonPressed
        && MOUSE.x >= 1134 && MOUSE.x <= 1226 &&
        MOUSE.y >= 484 && MOUSE.y <= 547) {
        sfSound_play(menu->sound);
    }
}

void settings(menu *menu)
{
    sfSprite_destroy(menu->menu_s);
    sfTexture_destroy(menu->t_menu);
    while (sfRenderWindow_isOpen(menu->window)) {
        settings_condition(menu);
        if (menu->event.type == sfEvtMouseButtonPressed &&
            MOUSE.x >= 1342 && MOUSE.x <= 1408 &&
            MOUSE.y >= 191 && MOUSE.y <= 256) {
            break;
        }
        sfRenderWindow_clear(menu->window, sfWhite);
        sfRenderWindow_drawSprite(menu->window, menu->settings, NULL);
        sfRenderWindow_display(menu->window);
    }
    sfSprite_destroy(menu->settings);
    sfTexture_destroy(menu->t_settings);
    init_menu(menu);
}

void click(menu *menu)
{
    data *data = malloc(sizeof(struct variables));

    if (MOUSE.x >= 770 && MOUSE.x <= 1011 &&
        MOUSE.y >= 760 && MOUSE.y <= 795 &&
        menu->event.type == sfEvtMouseButtonPressed){
        sfSprite_destroy(menu->menu_s);
        sfTexture_destroy(menu->t_menu);
        game_loop(data);
        free(data);
        init_menu(menu);
    }
    if (MOUSE.x >= 799 && MOUSE.x <= 1005 && MOUSE.y >= 820
        && MOUSE.y <= 902
        && menu->event.type == sfEvtMouseButtonPressed)
        sfRenderWindow_close(menu->window);
    if (MOUSE.x >= 759 && MOUSE.x <= 992 &&
        MOUSE.y >= 677 && MOUSE.y <= 723
        && menu->event.type == sfEvtMouseButtonPressed)
        settings(menu);
}

void init_menu(menu *menu)
{
    menu->mode.width = 1920;
    menu->mode.height = 1080;
    menu->mode.bitsPerPixel = 32;
    menu->window = WINDOW(menu->mode, "menu", sfResize | sfClose, NULL);
    menu->menu_s = sfSprite_create();
    menu->settings = sfSprite_create();
    menu->t_settings = FILE("img/settings.png", NULL);
    menu->t_menu = FILE("img/menul.png", NULL);
    menu->sound = sfSound_create();
    menu->musique = sfSoundBuffer_createFromFile("musique/menusong.ogg");
    sfSound_setBuffer(menu->sound, menu->musique);
    sfSprite_setTexture(menu->settings, menu->t_settings, sfTrue);
    sfSprite_setTexture(menu->menu_s, menu->t_menu, sfTrue);
}

void disp_menu(menu *menu)
{
    init_menu(menu);
    sfSound_play(menu->sound);
    while (sfRenderWindow_isOpen(menu->window)) {
        close_boucle_menu(menu);
        click(menu);
        sfRenderWindow_clear(menu->window, sfWhite);
        sfRenderWindow_drawSprite(menu->window, menu->menu_s, NULL);
        sfRenderWindow_display(menu->window);
    }
    sfSound_destroy(menu->sound);
    sfSprite_destroy(menu->menu_s);
    sfTexture_destroy(menu->t_menu);
    sfRenderWindow_destroy(menu->window);
}
