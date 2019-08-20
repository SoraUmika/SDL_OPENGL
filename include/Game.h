#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <utility.h>
#include <Root.h>
#include <LTexture.h>
#include <Player.h>
#include <Canvas.h>
#include <Map.h>
#include <SpriteSheet.h>
#include <Camera.h>
#include <Timer.h>
#include <TestClass.h>

enum AppStatus{inGame, inMainMenu, inSettings, inExit, inPause};

class Game: public Root{
    public:
        Game();
        void mainLoop();
        void setAppStatus(AppStatus status);
        void close();
        bool exit_status = false;

    private:
        void render();
        void keyEvents();
        void cameraEvents();
        SDL_Event event;
        AppStatus appStatus = inGame;

        //timing & fps
        //int fpsCap = 60;
        int fpsCount = 0;
        LTexture fpsTextTexture;
        void displayFPS();

        //GAME MAJOR OBJECTS
        Map currentMap;
        Canvas canvas;
        Player player;
        Camera camera;
        
        //INITIALIZE GAME OBJECT
        void initGameObject();

        simpleTimer m_timer;

        //testMembers
        //LTexture testTexture;
        //SDL_Rect testRect;
};

#endif