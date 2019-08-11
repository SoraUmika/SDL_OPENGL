#include <Root.h>

SDL_Window* Root::gWindow = NULL;
SDL_Renderer* Root::gRenderer = NULL;
SDL_Surface* Root::gWindowSurface = NULL;
TTF_Font* Root::defaultFont = NULL;

Root::Root(){

}

void Root::setRenderDrawColor(SDL_Color color){
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
}

TTF_Font* Root::loadFont(std::string path, int fontSize){
    TTF_Font* newFont = NULL;
    newFont = TTF_OpenFont(path.c_str(), fontSize);
    if(newFont == NULL){
        std::cout << "Unable to load font from " << path << " ! SDL Error: " << SDL_GetError() << std::endl;
    }
    return newFont;
}

SDL_Texture* Root::loadTextTexture(TTF_Font* font, std::string text, SDL_Color color){
    SDL_Texture* newTextTexture = NULL;
    SDL_Surface* message = TTF_RenderText_Solid(font, text.c_str(), color);
    newTextTexture = SDL_CreateTextureFromSurface(gRenderer, message); 
    if(newTextTexture == NULL){
        std::cout << "Unable to load text texture! SDL Error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(message);
    return newTextTexture;
}

SDL_Texture* Root::loadTexture(SDL_Renderer* renderer, std::string path){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* newSurface = IMG_Load(path.c_str());

    if(newSurface == NULL){
        std::cout << "Unable to load image " << path + "! SDL_image Error: " << IMG_GetError() << std::endl;

    }else{
        newTexture = SDL_CreateTextureFromSurface(renderer, newSurface);
        if(newTexture == NULL){
            std::cout << "Unable to create texture from " << path << " ! SDL Error: " << SDL_GetError() << std::endl;;
        }

        SDL_FreeSurface(newSurface);
    }

    return newTexture;
}