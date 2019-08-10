#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <settings.h>
#include <Map.h>
#include <Root.h>
#include <utility.h>

class Player: public Root{
    public:
        Player(SDL_Rect Rect = {0, 0, TILESIZE, TILESIZE*2});

        SDL_Rect getRect();
        
        void interact_map();
        void render();
        void events(SDL_Event &event);
    private:
        SDL_Rect Rect;
        Map currentMap;

        int movementSpeed = 20;
        SDL_Texture* texture;
};

#endif