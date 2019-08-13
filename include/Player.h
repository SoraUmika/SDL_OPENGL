#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>

class Player: public Root{
    public:
        Player(SDL_Rect Rect = {0, 0, TILESIZE/2, TILESIZE});
        
        void canvas();
        void render();
        void events(SDL_Event &event);


        SDL_Rect* getRectPtr();
    private:

        SDL_Rect pRect;
        LTexture pTexture;
        Canvas pCanvas;
        int movementSpeed = TILESIZE;
};

#endif