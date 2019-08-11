#ifndef LTEXTURE_H_INCLUDED
#define LTEXTURE_H_INCLUDED

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <Root.h>

class LTexture: public Root{
    public:
        void loadTextTexture(TTF_Font* font, std::string text, SDL_Color color);
        void loadTexture(std::string path);
        SDL_Texture* getTexture();
        
    private:
        SDL_Texture* mTexture;

        int mWdith;
        int mHeight;
};

#endif