#ifndef __Game_H_INCLUDED__
#define __Game_H_INCLUDED__

#include <iostream>
#include <SDL.h>

using namespace std;

class Game{
    public:
        Game();
        void menu();
        void close();

        void mainLoop();
        
        bool exit_status = false;

    private:
        SDL_Event events;

        SDL_Window* gWindow = NULL;
        SDL_Surface* gWindowSurface = NULL;
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
};

#endif