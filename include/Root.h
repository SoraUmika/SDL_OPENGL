#ifndef ROOT_H_INCLUDED
#define ROOT_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class Root{
    public:
        static SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;
        static SDL_Surface* gWindowSurface;

        void setRenderDrawColor(SDL_Color color);
        SDL_Texture* loadTextTexture(TTF_Font* font, std::string text, SDL_Color color);
    private:
};

#endif