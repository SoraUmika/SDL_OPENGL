#include <LTexture.h>

void LTexture::loadTextTexture(TTF_Font* font, std::string text, SDL_Color color){
    SDL_Texture* newTextTexture = NULL;
    SDL_Surface* message = TTF_RenderText_Solid(font, text.c_str(), color);
    newTextTexture = SDL_CreateTextureFromSurface(gRenderer, message); 
    if(newTextTexture == NULL){
        std::cout << "Unable to load text texture! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(message);
    mTexture =  newTextTexture;
}

void LTexture::loadTexture(std::string path){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* newSurface = IMG_Load(path.c_str());

    if(newSurface == NULL){
        std::cout << "Unable to load image " << path + "! SDL_image Error: " << IMG_GetError() << std::endl;

    }else{
        newTexture = SDL_CreateTextureFromSurface(gRenderer, newSurface);
        if(newTexture == NULL){
            std::cout << "Unable to create texture from " << path << " ! SDL Error: " << SDL_GetError() << std::endl;;
        }

        SDL_FreeSurface(newSurface);
    }

    mTexture =  newTexture;
}

SDL_Texture* LTexture::getTexture(){
    return mTexture;
}