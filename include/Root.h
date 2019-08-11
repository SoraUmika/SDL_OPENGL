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

        static void setRenderDrawColor(SDL_Color color);
        static SDL_Texture* loadTextTexture(TTF_Font* font, std::string text, SDL_Color color);
        static TTF_Font* loadFont(std::string path, int fontSize);
        static SDL_Texture* loadTexture(SDL_Renderer* renderer,std::string path);
        static TTF_Font* defaultFont;

        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 720;
    private:
};

#endif