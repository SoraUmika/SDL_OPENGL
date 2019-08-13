#include <SpriteSheet.h>

void SpriteSheet::loadSheet(std::string path, int tileSize){
    this->tileSize = tileSize;
    sheetTexture.loadTextureFromFile(path);
    SDL_QueryTexture(sheetTexture.getTexture(), NULL, NULL, &sheetSize_x, &sheetSize_y);
    
    if(sheetSize_x == 0 || sheetSize_y == 0){
        std::cout << "Sprite Sheet not initialize properly" << std::endl;
    }else{
        parseSheet();
    }
}

void SpriteSheet::parseSheet(){
    for(int j=0; j<sheetSize_y; j+=tileSize){
        for(int i=0; i<sheetSize_x; i+=tileSize){
            tilePos.push_back({i, j});
        }
    }
}