#include <utility.h>

SDL_Color chooseColor(enumColors color){
    switch(color){
        case RED:
            return {255, 0, 0, 255};
        case GREEN:
            return {0, 255, 0, 255};
        case BLUE:
            return {0, 0, 255, 255};
        case YELLOW:
            return {255, 255, 0, 255};
        case ORANGE:
            return {255, 165, 0, 255};
        case BLACK:
            return {0, 0, 0, 255};
        case WHITE:
            return {255, 255, 255, 255};
        default:
            throw "Invalid color";
    }
};

void drawRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color fillColor){
    SDL_SetRenderDrawColor(renderer, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    SDL_RenderFillRect(renderer, &rect);
}

