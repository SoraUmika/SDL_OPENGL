#include <SpriteSheet.h>

void SpriteSheet::loadSheet(std::string path, int tileSize){
    this->tileSize = tileSize;
    Texture.loadTextureFromFile(path);
    SDL_QueryTexture(Texture.getTexture(), NULL, NULL, &sheetSize_x, &sheetSize_y);
    
    if(sheetSize_x == 0 || sheetSize_y == 0){
        std::cout << "Sprite Sheet not initialize properly!" << std::endl;
    }else{
        parseSheet();
    }
}

void SpriteSheet::parseSheet(){
    for(int j=0; j<sheetSize_y; j+=tileSize){
        for(int i=0; i<sheetSize_x; i+=tileSize){
            ssTilePos.push_back({i, j});
        }
    }
}

void SpriteSheet::loadAnimTileSet(AnimSet down, AnimSet left, AnimSet right, AnimSet up){
    for(int i=0; i<left.tileIndices.size(); i++){
        walkCycleLeft.push_back(ssTilePos.at(left.tileIndices.at(i)));
    }
    for(int i=0; i<right.tileIndices.size(); i++){
        walkCycleRight.push_back(ssTilePos.at(right.tileIndices.at(i)));
    }
    for(int i=0; i<up.tileIndices.size(); i++){
        walkCycleUp.push_back(ssTilePos.at(up.tileIndices.at(i)));
    }
    for(int i=0; i<down.tileIndices.size(); i++){
        walkCycleDown.push_back(ssTilePos.at(down.tileIndices.at(i)));
    }
    currentClip = {walkCycleDown.at(0).x, walkCycleDown.at(0).y, tileSize, tileSize};
}

void SpriteSheet::setCurrentClip(Direction direction){
    if(indexDown < walkCycleDown.size() && indexLeft < walkCycleLeft.size() && indexRight < walkCycleRight.size() && indexUp < walkCycleUp.size()){
        switch(direction){
            case DOWN:
                currentClip = {walkCycleDown.at(indexDown).x, walkCycleDown.at(indexDown).y, tileSize, tileSize};
                indexDown += 1;
                indexLeft = 0;
                indexRight = 0;
                indexUp = 0;
                break;
            case UP:
                currentClip = {walkCycleUp.at(indexUp).x, walkCycleUp.at(indexUp).y, tileSize, tileSize};
                indexUp += 1;
                indexLeft = 0;
                indexDown = 0;
                indexRight = 0;
                break;
            case LEFT:
                currentClip = {walkCycleLeft.at(indexLeft).x, walkCycleLeft.at(indexLeft).y, tileSize, tileSize};
                indexLeft += 1;
                indexDown = 0;
                indexUp = 0;
                indexRight = 0;
                break;
            case RIGHT:
                currentClip = {walkCycleRight.at(indexRight).x, walkCycleRight.at(indexRight).y, tileSize, tileSize};
                indexRight += 1;
                indexLeft = 0;
                indexUp = 0;
                indexDown = 0;
                break;
        }
    }else{
        indexRight = 0;
        indexLeft = 0;
        indexUp = 0;
        indexDown = 0;
    }
}