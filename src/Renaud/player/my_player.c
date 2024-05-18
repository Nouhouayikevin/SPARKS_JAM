/*
** EPITECH PROJECT, 2024
** my_player.c
** File description:
** my_player.c
*/

#include "my.h"


void creator(new_struct *hunter)
{
    sfVideoMode mode = {1920, 1080, 64};
    hunter->win = sfRenderWindow_create(mode, "RMV", sfResize | sfClose, NULL);
    hunter->game = sfTexture_createFromFile("res/lack.jpg", NULL);
    hunter->sprite_game = sfSprite_create();
    sfSprite_setTexture(hunter->sprite_game, hunter->game, sfTrue);
}

int create_player(player *gamer)
{
  
    gamer ->player = sfSprite_create();
    gamer->clock = sfClock_create();
    sfSprite_setTexture(gamer ->player, gamer ->p_texture, sfTrue);
    sfVector2f scale = {0.8, 0.8};
    sfSprite_setScale(gamer -> player, scale);
}
void draw_text(my_text **tab_of_text, player*game, new_struct *hunter)
{
        if(game->seconds > 0.1)
        sfRenderWindow_drawText(hunter->win, tab_of_text[1]->text,NULL);
        if(game->seconds > 5)
            sfRenderWindow_drawText(hunter->win ,tab_of_text[2]->text, NULL);
        if(game->seconds > 7)
            sfRenderWindow_drawText(hunter->win, tab_of_text[3]->text, NULL);
        if(game->seconds > 9)
            sfRenderWindow_drawText(hunter->win, tab_of_text[4]->text, NULL);
    
}
void menu_and_game_launch(new_struct *hunter , player *game)
{
    my_text ** tab_of_text = malloc(sizeof(my_text) * 8);
     def_texts(tab_of_text);
    while (sfRenderWindow_isOpen(hunter->win)){
    game ->time = sfClock_getElapsedTime(game ->clock);
    game ->seconds = game->time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(hunter->win, &(hunter->event))){
              if (hunter->event.type == sfEvtClosed){
            sfRenderWindow_close(hunter->win);
        }
        }
        sfRenderWindow_drawSprite(hunter->win, hunter->sprite_game, NULL);
        draw_text(tab_of_text,game,hunter);
        sfRenderWindow_display(hunter->win);
        if(game->seconds > 14)
        sfRenderWindow_close(hunter->win);
    }
    sfTexture_destroy(hunter->game);
    sfSprite_destroy(hunter->sprite_game);
    sfClock_destroy(hunter->clock);
    sfRenderWindow_destroy(hunter->win);
}

void defeat_appear()
{
    new_struct *hunter = malloc(sizeof(new_struct));
    player *game  = malloc(sizeof(player));
    sfRectangleShape *renaud;
    creator(hunter);
    create_player(game);
    menu_and_game_launch(hunter ,game);
}
int main(int ac, char *av)
{
    defeat_appear();
}