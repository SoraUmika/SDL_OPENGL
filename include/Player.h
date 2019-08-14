#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>

class Player: public Root{
    public:
        Player(int x = 0, int y = 0, int width = TILESIZE, int heigh = TILESIZE*2);
        
        void render(SDL_Rect cameraRect);
        void events(SDL_Event &event);

        int getPos_x();
        int getPos_y();

        SDL_Rect* getRectPtr();
        SDL_Rect getRect();
    private:

        SDL_Rect pRect;
        SDL_Rect tmpRect;
        SDL_Rect camRect;
        LTexture pTexture;
        Canvas pCanvas;
        void canvas();

        int movementSpeed = TILESIZE/4;

        int pos_x;
        int pos_y;

};

#endif