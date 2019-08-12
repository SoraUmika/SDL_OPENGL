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
        void free();
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
        SDL_Texture* getTexture();

    private:
        SDL_Texture* mTexture;

        int mWidth;
        int mHeight;
};

#endif