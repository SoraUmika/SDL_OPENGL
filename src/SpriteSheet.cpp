#include <SpriteSheet.h>

void SpriteSheet::loadSheet(std::string path, int tileSizeX, int tileSizeY){
    this->tileSizeX = tileSizeX;
    this->tileSizeY = tileSizeY;
    Texture.loadTextureFromFile(path);
    SDL_QueryTexture(Texture.getTexture(), NULL, NULL, &sheetSize_x, &sheetSize_y);
    
    if(sheetSize_x == 0 || sheetSize_y == 0){
        std::cout << "Sprite Sheet not initialize properly!" << std::endl;
    }else{
        parseSheet();
    }
}

void SpriteSheet::parseSheet(){
    for(int j=0; j<sheetSize_y; j+=tileSizeY){
        for(int i=0; i<sheetSize_x; i+=tileSizeX){
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
    currentClip = {walkCycleDown.at(0).x, walkCycleDown.at(0).y, tileSizeX, tileSizeY};
}

void SpriteSheet::setCurrentClip(Direction direction){
    if(indexDown < walkCycleDown.size()-1 && indexLeft < walkCycleLeft.size()-1 && indexRight < walkCycleRight.size()-1 && indexUp < walkCycleUp.size()-1){
        switch(direction){
            case DOWN:
                indexDown += 1;
                currentClip = {walkCycleDown.at(indexDown).x, walkCycleDown.at(indexDown).y, tileSizeX, tileSizeY};
                indexLeft = 0;
                indexRight = 0;
                indexUp = 0;
                break;
            case UP:
                indexUp += 1;
                currentClip = {walkCycleUp.at(indexUp).x, walkCycleUp.at(indexUp).y, tileSizeX, tileSizeY};
                indexLeft = 0;
                indexDown = 0;
                indexRight = 0;
                break;
            case LEFT:
                indexLeft += 1;
                currentClip = {walkCycleLeft.at(indexLeft).x, walkCycleLeft.at(indexLeft).y, tileSizeX, tileSizeY};
                indexDown = 0;
                indexUp = 0;
                indexRight = 0;
                break;
            case RIGHT:
                indexRight += 1;
                currentClip = {walkCycleRight.at(indexRight).x, walkCycleRight.at(indexRight).y, tileSizeX, tileSizeY};
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
        switch(direction){
            case DOWN:
                currentClip = {walkCycleDown.at(indexDown).x, walkCycleDown.at(indexDown).y, tileSizeX, tileSizeY};
                break;
            case UP:
                currentClip = {walkCycleUp.at(indexUp).x, walkCycleUp.at(indexUp).y, tileSizeX, tileSizeY};
                break;
            case LEFT:
                currentClip = {walkCycleLeft.at(indexLeft).x, walkCycleLeft.at(indexLeft).y, tileSizeX, tileSizeY};
                break;
            case RIGHT:
                currentClip = {walkCycleRight.at(indexRight).x, walkCycleRight.at(indexRight).y, tileSizeX, tileSizeY};
                break;
        };
    }
}