#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

enum enumColors{RED, GREEN, BLUE, YELLOW, ORANGE, BLACK, WHITE};

enum AnimeType{MOVE_LEFT, MOVE_RIGHT, MOVE_UP, MOVE_DOWN, STAND_BY};

enum Direction{LEFT, RIGHT, UP, DOWN};

int getMinVal(int val1, int val2);

int getMaxVal(int val1, int val2);

SDL_Color chooseColor(enumColors color, Uint8 opacity = 255);

TTF_Font* loadFont(std::string path, int fontSize);

#endif