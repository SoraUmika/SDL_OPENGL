#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <utility.h>
#include <Player.h>
#include <Root.h>

using namespace std;

enum appStatus{inGame, inMainMenu, inSettings, inExit, inPause};

class Game: public Root{
    public:
        Game();
        void menu();
        void close();

        void events(appStatus status);
        void mainLoop();
        
        bool exit_status = false;

    private:
        void render();

        SDL_Event event;
        const int SCREEN_WIDTH = 1280;
        const int SCREEN_HEIGHT = 720;
        
        void initBasicObject();

        Player player;
};

#endif