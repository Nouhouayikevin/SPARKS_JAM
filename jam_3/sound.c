/*
** EPITECH PROJECT, 2024
** sound.c
** File description:
** This is for handling thes song
*/

#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

affiche click_sound(void)
{
    affiche sound;

    sound.sound = sfSound_create();
    sound.soundbuffer = sfSoundBuffer_createFromFile("./click.ogg");
    return sound;
}
