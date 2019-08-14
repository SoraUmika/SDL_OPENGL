#include <Canvas.h>

void Canvas::drawGrid(int gridSize, enumColors color){
    setRenderDrawColor(chooseColor(color));
    for(int i=0; i < SCREEN_WIDTH; i+=TILESIZE){
        SDL_RenderDrawLine(gRenderer, i, 0, i, SCREEN_HEIGHT);
    }

    for(int j=0; j < SCREEN_HEIGHT; j+=TILESIZE){
        SDL_RenderDrawLine(gRenderer, 0, j, SCREEN_WIDTH, j);
    }
}

void Canvas::drawRect(SDL_Rect *rect, enumColors color){
    setRenderDrawColor(chooseColor(color));
    SDL_RenderFillRect(gRenderer, rect);
}