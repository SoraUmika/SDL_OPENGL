#include <Root.h>

SDL_Window* Root::gWindow = NULL;
SDL_Renderer* Root::gRenderer = NULL;
SDL_Surface* Root::gWindowSurface = NULL;


void Root::setRenderDrawColor(SDL_Color color){
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
}