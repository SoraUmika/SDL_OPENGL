#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <settings.h>
#include <Map.h>

class Player{
    public:
        Player(SDL_Rect Rect = {0, 0, TILESIZE, TILESIZE*2});

        SDL_Rect getRect();

        void update();
        void interact_map();
    private:
        void events(SDL_Event &e);
        void render(SDL_Renderer* renderer);
        SDL_Rect Rect;
        Map currentMap;
};

#endif