#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <settings.h>

class Player{
    public:
        Player(SDL_Rect Rect = {0, 0, TILESIZE, TILESIZE*2});

        SDL_Rect getRect();
    private:
        SDL_Rect Rect;
};

#endif