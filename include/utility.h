#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

enum enumColors{
    RED, GREEN, BLUE, YELLOW, ORANGE, BLACK, WHITE
};

SDL_Color chooseColor(enumColors color, Uint8 opacity = 255);

TTF_Font* loadFont(std::string path, int fontSize);

#endif