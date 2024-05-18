/*
** EPITECH PROJECT, 2024
** move_player.c
** File description:
** move_player.c
*/

#include "my.h"

my_text *init_text(sfVector2f position, unsigned int size, char *str,
char *filename)
{
    sfUint32 style; my_text *texte = malloc(sizeof(my_text));
    texte -> text = sfText_create(); texte->actif = sfTrue;
    sfFont *ft = sfFont_createFromFile(filename);
    sfColor gris = sfColor_fromRGB(205,204,198);
    texte -> button_status = sfFalse; texte -> color = sfWhite;
    texte -> active_color = sfColor_fromRGB(51,51,51);
    texte -> survol_color = sfColor_fromRGB(205,204,198);
    sfText_setPosition(texte -> text, position);
    sfText_setFillColor(texte -> text, texte -> survol_color);
    sfText_setOutlineColor(texte -> text, sfRed);
    sfText_setOutlineThickness(texte -> text, 3);
    sfText_setStyle(texte -> text, style);
    sfText_setString(texte -> text, str);
    sfText_setFont(texte -> text, ft);
    sfText_setCharacterSize(texte -> text, size);
    return texte;
}
my_text **def_texts(my_text **tab_of_text)
{
    tab_of_text[0] = init_text((sfVector2f){590, 210}, 80,\
    "OU REACH THE GOAL","res/DS Stamper.ttf");
    tab_of_text[1] = init_text((sfVector2f){600, 220},50,\
    "YOU REACH THE GOAL !!!", "res/DS Stamper.ttf");
    tab_of_text[2] = init_text((sfVector2f){600, 380},50,\
     "keep a mentality of a winner that you are....", "res/DS Stamper.ttf");
    tab_of_text[3] = init_text((sfVector2f){600, 500},50,\
    "Therefore YOU are a AUTHENTIC , OLYMPIC player......", "res/DS Stamper.ttf");
    tab_of_text[4] = init_text((sfVector2f){600, 620},50,\
    "see you soon for next challenges........", "res/DS Stamper.ttf");
    tab_of_text[5] = init_text((sfVector2f){800, 150},70,\
    "VOLUME", "res/DS Stamper.ttf");
    tab_of_text[6] = init_text((sfVector2f){800, 500},70,\
    "screen", "res/DS Stamper.ttf");
    tab_of_text[7] = init_text((sfVector2f){200, 500},70,\
    "for this quest kill 20 bird\nfor eat", "res/DS Stamper.ttf");
}
