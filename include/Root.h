#ifndef ROOT_H_INCLUDED
#define ROOT_H_INCLUDED

#include <SDL.h>

class Root{
    public:
        static SDL_Window* gWindow;
        static SDL_Renderer* gRenderer;
        static SDL_Surface* gWindowSurface;

        void setRenderDrawColor(SDL_Color color);
    private:
};

#endif