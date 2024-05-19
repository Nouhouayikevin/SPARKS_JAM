/*
** EPITECH PROJECT, 2024
** animation
** File description:
** 
*/

#include "animation.h"

void events(anim_t *anim, sfRenderWindow * win)
{
    if (anim->e.type == sfEvtKeyPressed && anim->e.key.code == sfKeyEscape)
        sfRenderWindow_close(win);
    if (anim->e.type == sfEvtClosed)
        sfRenderWindow_close(win);
}
