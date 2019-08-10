#ifndef __Game_H_INCLUDED__
#define __Game_H_INCLUDED__

#include <iostream>
#include <SDL.h>
#include <string>
#include <utility.h>

using namespace std;

class Game{
    public:
        Game();
        void menu();
        void close();

        void events();
        void mainLoop();
        
        bool exit_status = false;

    private:
        void render();
        void setRenderDrawColor(SDL_Color color);

        SDL_Event event;
        SDL_Window* gWindow = NULL;
        SDL_Surface* gWindowSurface = NULL;
        SDL_Renderer* gRenderer = NULL;
        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 720;
        
        SDL_Color renderColor = {255, 0, 0, 255};
};

#endif