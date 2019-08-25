#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <Utility.h>
#include <Root.h>
#include <LTexture.h>
#include <Player.h>
#include <Canvas.h>
#include <Map.h>
#include <SpriteSheet.h>
#include <Camera.h>
#include <Timer.h>
#include <Containers.h>
#include <TestClass.h>

enum AppStatus{inGame, inMainMenu, inSettings, inExit, inPause};
enum mapName{mageCity, caveTown};

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
        void mapEvents();
        void cameraEvents();
        void loadNewMap(std::string mapInfo, std::string mapTiles);
        SDL_Event event;
        AppStatus appStatus = inGame;

        
        //timing & fps
        int fpsCount = 0;
        LTexture fpsTextTexture;
        void displayFPS();

        //GAME MAJOR OBJECTS
        std::vector<Map> MapList;
        Map currentMap;
        Canvas canvas;
        Player player;
        Camera camera;
        
        mapName currentMapName = mageCity;
        //INITIALIZE GAME OBJECT
        void initGameObject();
        simpleTimer m_timer;
};

#endif