#include <utility.h>

SDL_Color chooseColor(enumColors color, Uint8 opacity){
    switch(color){
        case RED:
            return {255, 0, 0, opacity};
        case GREEN:
            return {0, 255, 0, opacity};
        case BLUE:
            return {0, 0, 255, opacity};
        case YELLOW:
            return {255, 255, 0, opacity};
        case ORANGE:
            return {255, 165, 0, opacity};
        case BLACK:
            return {0, 0, 0, opacity};
        case WHITE:
            return {255, 255, 255, opacity};
        default:
            throw "Invalid color";
    }
};


TTF_Font* loadFont(std::string path, int fontSize){
    TTF_Font* newFont = NULL;
    newFont = TTF_OpenFont(path.c_str(), fontSize);
    if(newFont == NULL){
        std::cout << "Unable to load font from " << path << " ! SDL Error: " << SDL_GetError() << std::endl;
    }
    return newFont;
}

int getMinVal(int val1, int val2){
    if(val1 < val2){
        return val1; 
    }else{
        return val2;
    }
}

int getMaxVal(int val1, int val2){
    if(val1 > val2){
        return val1;
    }else{
        return val2;
    }
}