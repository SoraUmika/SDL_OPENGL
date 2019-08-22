#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>
#include <Utility.h>
#include <Sprite.h>
#include <Timer.h>
#include <vector>
#include <Containers.h>

class Player: public Root, public Sprite{
    public:
        Player(int x = 0, int y = 0, int width = TILESIZE, int height = TILESIZE);
        void render(SDL_Rect renderRect);
        void events();

        std::vector<Wall>* mapWalls = NULL;
        bool collide_with_walls(int dx=0, int dy=0);
        void loadSpriteSheet(std::string path);
        SDL_Rect* getRectPtr();
    private:

        SDL_Rect camRect;
        SpriteSheet playerTiles; 
        Canvas pCanvas; 
        void canvas();
        void keyEvents();

        void animation(AnimeType animeType);
        Specicialized_V<int> run;
        int movementSpeed = 4;
        bool running = false;

};

#endif