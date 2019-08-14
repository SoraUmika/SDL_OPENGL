#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>

class Player: public Root{
    public:
        Player(SDL_Rect Rect = {0, 0, TILESIZE, TILESIZE*2});
        
        void canvas();
        void render();
        void events(SDL_Event &event);

        
        SDL_Rect* getRectPtr();
        //SDL_Rect* getRenderRectPtr();
        SDL_Rect getRect();
    private:

        SDL_Rect pRect;
        //SDL_Rect rRect;
        LTexture pTexture;
        Canvas pCanvas;
        int movementSpeed = TILESIZE;

};

#endif