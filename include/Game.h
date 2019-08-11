#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <utility.h>
#include <Root.h>
#include <LTexture.h>
#include <Player.h>

using namespace std;

enum appStatus{inGame, inMainMenu, inSettings, inExit, inPause};

class Game: public Root{
    public:
        Game();
        void mainLoop();
        bool exit_status = false;

    private:
        void menu();
        void render();
        void close();
        void events(appStatus status);

        SDL_Event event;

        //timing & fps
        int fpsCap = 60;
        int fpsCount = 0;
        int timeTicks = 0;
        SDL_Rect fpsRect = {5, 5, 100, 24};
        LTexture fpsTextTexture;
        void displayFPS();
        Player player;

};

#endif