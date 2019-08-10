#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <iostream>
#include <SDL.h>

using namespace std;

enum enumColors{
    RED, GREEN, BLUE, YELLOW, ORANGE, BLACK, WHITE
};

SDL_Color chooseColor(enumColors color);

void drawRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color fillColor);

#endif