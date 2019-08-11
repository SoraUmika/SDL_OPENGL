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

SDL_Texture* loadTexture(SDL_Renderer* renderer,string path){
    SDL_Texture* newTexture = NULL;
    SDL_Surface* newSurface = IMG_Load(path.c_str());

    if(newSurface == NULL){
        cout << "Unable to load image " << path + "! SDL_image Error: " << IMG_GetError() << endl;

    }else{
        newTexture = SDL_CreateTextureFromSurface(renderer, newSurface);
        if(newTexture == NULL){
            cout << "Unable to create texture from " << path << " ! SDL Error: " << SDL_GetError() << endl;;
        }

        SDL_FreeSurface(newSurface);
    }

    return newTexture;
}

TTF_Font* loadFont(string path, int fontSize){
    TTF_Font* newFont = NULL;
    newFont = TTF_OpenFont(path.c_str(), fontSize);
    if(newFont == NULL){
        cout << "Unable to load font from " << path << " ! SDL Error: " << SDL_GetError() << endl;
    }
    return newFont;
}
