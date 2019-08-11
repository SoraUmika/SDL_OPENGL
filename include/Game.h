#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <utility.h>
#include <Player.h>
#include <Root.h>
#include <SDL_ttf.h>

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
    
        void initBasicObject();

        //timing & fps
        int fpsCount;
        int timeTicks;
        SDL_Rect fpsRect;
        SDL_Texture* fpsTextTexture;
        void displayFPS();
        Player player;
};

#endif