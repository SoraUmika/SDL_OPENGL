#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>
#include <utility.h>

class Player: public Root{
    public:
        Player(int x = 0, int y = 0, int width = TILESIZE, int heigh = TILESIZE*2);
        
        void render(SDL_Rect cameraRect);
        void events();

        void load_ss(std::string path);
        SDL_Rect* getRectPtr();
        SDL_Rect getRect();
    private:

        SDL_Rect pRect;
        SDL_Rect tmpRect;
        SDL_Rect camRect;
        LTexture pTexture;
        SpriteSheet pSS;
        Canvas pCanvas;
        void canvas();

        void animation(Direction direction);
        int previousTick = 0;
        
        int movementSpeed = 4;
        bool running = false;

};

#endif