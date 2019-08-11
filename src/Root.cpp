#include <Root.h>

SDL_Window* Root::gWindow = NULL;
SDL_Renderer* Root::gRenderer = NULL;
SDL_Surface* Root::gWindowSurface = NULL;


void Root::setRenderDrawColor(SDL_Color color){
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
}

SDL_Texture* Root::loadTextTexture(TTF_Font* font, std::string text, SDL_Color color){
    SDL_Texture* newTextTexture = NULL;
    static SDL_Surface* Message = TTF_RenderText_Solid(font, text.c_str(), color);
    newTextTexture = SDL_CreateTextureFromSurface(gRenderer, Message); 
    if(newTextTexture == NULL){
        std::cout << "Unable to load text texture! SDL Error: " << SDL_GetError() << std::endl;
    }
    return newTextTexture;
}