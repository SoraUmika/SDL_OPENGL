#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SDL.h>
#include <Root.h>
#include <LTexture.h>
#include <Canvas.h>
#include <SpriteSheet.h>
#include <utility.h>
#include <Sprite.h>
#include <Timer.h>
#include <vector>

class Player: public Root, public Sprite{
    public:
        Player(int x = 0, int y = 0, int width = TILESIZE, int heigh = TILESIZE*2);
        
        void render(SDL_Rect renderRect);
        void events();

        void loadSpriteSheet(std::string path);
        SDL_Rect* getRectPtr();
        SDL_Rect getRect();
    private:

        SDL_Rect tmpRect;
        SDL_Rect camRect;
        LTexture pTexture;
        SpriteSheet pSS;
        Canvas pCanvas; 
        void canvas();
        void keyEvents();
        void movements(Direction direction);

        void animation(AnimeType animeType);
        void animationS(Direction direction);
        int previousTick = 0;
        
        int movementSpeed = 4;
        bool running = false;

};

#endif