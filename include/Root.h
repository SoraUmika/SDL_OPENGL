#ifndef ROOT_H_INCLUDED
#define ROOT_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class Root{
    public:
        Root();
        static SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;
        static SDL_Surface* gWindowSurface;
        static TTF_Font* defaultFont;

        static void setRenderDrawColor(SDL_Color color);

        static const int SCREEN_WIDTH = 1280;
        static const int SCREEN_HEIGHT = 720;
        static const int TILESIZE = 32;
    
    private:
};

#endif