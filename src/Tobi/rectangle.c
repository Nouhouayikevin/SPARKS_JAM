/*
** EPITECH PROJECT, 2024
** rectangle.c
** File description:
** THis is my rectangle
*/

#include "../../include/jam.h"

rect_t *create_rectangle(rect_t *rectangle)
{
    sfVector2f size = {30, 30};
    sfVector2f posi = {200, 787};
    rectangle = malloc(sizeof(rect_t) * 8);
    int i = 0;
    for (i = 0; i < 8; i++)
        rectangle[i].rect = sfRectangleShape_create();
    i = 0;
    //fire 1
    posi.x += 32;
    posi.y += 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    // fire 2
    posi.x = 180 + 32;
    posi.y = 80 + 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    // fire 3
    posi.x = 980 + 32;
    posi.y = 420 + 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    // fire 4
    posi.x = 970 + 32;
    posi.y = 715 + 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    // fire 5
    posi.x = 1600 + 32;
    posi.y = 50 + 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    // fire 6
    posi.x = 1780 + 32;
    posi.y = 860 + 55;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    rectangle[i].rect = NULL;
    return rectangle;
}


rect_t *my_rectangle(rect_t *rectangle)
{

    sfVector2f size = {30, 800};
    sfVector2f posi = {120, 90};
    rectangle = malloc(sizeof(rect_t) * 300);
    int i = 0;
    for (i = 0; i < 300; i++)
        rectangle[i].rect = sfRectangleShape_create();
    i = 0;
    //totalement à gauche
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //totalement en haut
    size.x = 1800;
    size.y = 15;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //totalement en bas
    size.x = 1800;
    size.y = 20;
    posi.y = 970; 
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //totalement à droite
    size.x = 40;
    size.y = 800;
    posi.x = 1890;
    posi.y = 160;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //premier trait à droite
    size.x = 400;
    size.y = 20;
    posi.x = 1600;
    posi.y = 160;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //deuxième trait à droite
    size.x = 380;
    size.y = 15;
    posi.x = 1750;
    posi.y = 380;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //premier trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 400;
    posi.y = 150;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //deuxième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 690;
    posi.y = 150;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //troisième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 1080;
    posi.y = 150;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //quatrième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 1340;
    posi.y = 150;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //cinquième trait parrallèle à trait totalement en haut
    size.x = 830;
    size.y = 25;
    posi.x = 795;
    posi.y = 228;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //sixième trait parrallèle à trait totalement en haut
    size.x = 130;
    size.y = 25;
    posi.x = 1195;
    posi.y = 302;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //septième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 155;
    posi.y = 222;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //huitième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 155;
    posi.y = 222;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //neuvième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 505;
    posi.y = 300;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //dixième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 505;
    posi.y = 375;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //onzième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 1080;
    posi.y = 375;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //douzième trait parrallèle à trait totalement en haut
    size.x = 150;
    size.y = 25;
    posi.x = 1450;
    posi.y = 595;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //douzième trait parrallèle à trait totalement en haut
    size.x = 710;
    size.y = 25;
    posi.x = 650;
    posi.y = 595;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //treizième trait parrallèle à trait totalement en haut
    size.x = 280;
    size.y = 25;
    posi.x = 780;
    posi.y = 510;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //quatorzième trait parrallèle à trait totalement en haut
    size.x = 280;
    size.y = 25;
    posi.x = 280;
    posi.y = 510;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //quinzième trait parrallèle à trait totalement en haut
    size.x = 280;
    size.y = 25;
    posi.x = 280;
    posi.y = 435;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //seizième trait parrallèle à trait totalement en haut
    size.x = 110;
    size.y = 25;
    posi.x = 155;
    posi.y = 595;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //dix_septième trait parrallèle à trait totalement en haut
    size.x = 110;
    size.y = 25;
    posi.x = 385;
    posi.y = 595;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //dix_huitième trait parrallèle à trait totalement en haut
    size.x = 210;
    size.y = 25;
    posi.x = 155;
    posi.y = 730;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //dix_neuvième trait parrallèle à trait totalement en haut
    size.x = 190;
    size.y = 25;
    posi.x = 245;
    posi.y = 820;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinghtième trait parrallèle à trait totalement en haut
    size.x = 990;
    size.y = 25;
    posi.x = 645;
    posi.y = 820;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_unième trait parrallèle à trait totalement en haut
    size.x = 570;
    size.y = 28;
    posi.x = 645;
    posi.y = 735;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_deuxième trait parrallèle à trait totalement en haut
    size.x = 470;
    size.y = 28;
    posi.x = 1295;
    posi.y = 740;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_troisième trait parrallèle à trait totalement en haut
    size.x = 455;
    size.y = 28;
    posi.x = 1310;
    posi.y = 890;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_quatiième trait parrallèle à trait totalement en haut
    size.x = 670;
    size.y = 28;
    posi.x = 540;
    posi.y = 890;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_cinquième trait parrallèle à trait totalement en haut
    size.x = 500;
    size.y = 28;
    posi.x = 540;
    posi.y = 660;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_sixième trait parrallèle à trait totalement en haut
    size.x = 540;
    size.y = 28;
    posi.x = 540;
    posi.y = 660;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_septième trait parrallèle à trait totalement en haut
    size.x = 300;
    size.y = 28;
    posi.x = 1190;
    posi.y = 660;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_huitième trait parrallèle à trait totalement en haut
    size.x = 170;
    size.y = 28;
    posi.x = 920;
    posi.y = 440;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_huitième trait parrallèle à trait totalement en haut
    size.x = 35;
    size.y = 310;
    posi.x = 785;
    posi.y = 225;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_huitième trait parrallèle à trait totalement en haut
    size.x = 31;
    size.y = 95;
    posi.x = 785;
    posi.y = 595;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //vinght_neuvième trait parrallèle à trait totalement en haut
    size.x = 31;
    size.y = 95;
    posi.x = 1185;
    posi.y = 665;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //trentième trait parrallèle à trait totalement en haut
    size.x = 31;
    size.y = 95;
    posi.x = 1740;
    posi.y = 815;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    //trente_unième trait parrallèle à trait totalement en haut
    size.x = 31;
    size.y = 95;
    posi.x = 1735;
    posi.y = 160;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    i++;
    // trait dans le deuxième trait à droite
    size.x = 20;
    size.y = 310;
    posi.x = 1740;
    posi.y = 300;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //premier trait parrallèle au trait dans le deuxième trait à droite
    size.x = 25;
    size.y = 540;
    posi.x = 1600;
    posi.y = 300;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //deuxième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 20;
    size.y = 370;
    posi.x = 1470;
    posi.y = 250;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //troisième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 30;
    size.y = 320;
    posi.x = 1330;
    posi.y = 290;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //quatrième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 170;
    posi.x = 1200;
    posi.y = 370;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //cinquième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 170;
    posi.x = 1320;
    posi.y = 70;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //sixième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 165;
    posi.x = 1050;
    posi.y = 230;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //septième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 105;
    posi.x = 1050;
    posi.y = 77;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //huitième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 105;
    posi.x = 1050;
    posi.y = 740;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //neufième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 105;
    posi.x = 1050;
    posi.y = 440;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //dixième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 105;
    posi.x = 1050;
    posi.y = 890;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //onzième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 95;
    posi.x = 920;
    posi.y = 90;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //douzième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 95;
    posi.x = 920;
    posi.y = 230;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //treizième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 35;
    size.y = 95;
    posi.x = 920;
    posi.y = 364;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //quatorzième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 40;
    size.y = 445;
    posi.x = 650;
    posi.y = 90;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //quinzième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 40;
    size.y = 385;
    posi.x = 500;
    posi.y = 520;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //seizième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 40;
    size.y = 145;
    posi.x = 510;
    posi.y = 90;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //dix-septième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 395;
    posi.y = 150;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //dix-huitième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 168;
    posi.x = 395;
    posi.y = 300;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //dix-neuvième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 370;
    posi.y = 590;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinghtième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 370;
    posi.y = 740;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_unième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 370;
    posi.y = 885;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_deuxième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 240;
    posi.y = 885;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_troisième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 45;
    size.y = 100;
    posi.x = 240;
    posi.y = 585;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_quatrième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 55;
    size.y = 95;
    posi.x = 240;
    posi.y = 85;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_cinquième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 50;
    size.y = 225;
    posi.x = 240;
    posi.y = 305;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //vinght_sixième trait parrallèle au trait dans le deuxième trait à droite
    size.x = 50;
    size.y = 225;
    posi.x = 240;
    posi.y = 305;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //toisième trait à droite
    size.x = 380;
    size.y = 15;
    posi.x = 1742;
    posi.y = 680;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    //quatrième trait à droite
    size.x = 380;
    size.y = 15;
    posi.x = 1742;
    posi.y = 830;
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setOutlineColor(rectangle[i].rect, sfTransparent);
    sfRectangleShape_setPosition(rectangle[i].rect, posi);
    sfRectangleShape_setSize(rectangle[i].rect, size);
    sfRectangleShape_setOutlineThickness(rectangle[i].rect, 1.6);
    sfRectangleShape_setFillColor(rectangle[i].rect, sfTransparent);
    i++;
    rectangle[i].rect = NULL;
    return rectangle;
}