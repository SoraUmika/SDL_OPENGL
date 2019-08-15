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
    for(int i=0; i<down.tileIndices.size();i++){
        walkCycleIndices.push_back(down.tileIndices.at(i));
    }
    for(int i=0; i<left.tileIndices.size();i++){
        walkCycleIndices.push_back(left.tileIndices.at(i));
    }
    for(int i=0; i<right.tileIndices.size();i++){
        walkCycleIndices.push_back(right.tileIndices.at(i));
    }
    for(int i=0; i<up.tileIndices.size();i++){
        walkCycleIndices.push_back(up.tileIndices.at(i));
    }
    
    indicesPerSet = down.tileIndices.size();
    currentAnimIndex = 0;
}

int boundValue(int currentVal, int minVal, int maxVal){
    if(currentVal == maxVal){
        return minVal;
    }else{
        return currentVal;
    }
}

void SpriteSheet::setCurrentClip(Direction direction){
    switch(direction){
        case DOWN:
            static int indexDown = indicesPerSet * 0;
            indexDown = boundValue(indexDown, indicesPerSet * 0, indicesPerSet * 1);
            currentAnimIndex = indexDown;
            indexDown += 1;
            break;
        case LEFT:
            static int indexLeft = indicesPerSet * 1;
            indexLeft = boundValue(indexLeft, indicesPerSet * 1, indicesPerSet * 2);
            currentAnimIndex = indexLeft;
            indexLeft += 1;
            break;
        case RIGHT:
            static int indexRight = indicesPerSet * 2;
            indexRight = boundValue(indexRight, indicesPerSet * 2, indicesPerSet * 3);
            currentAnimIndex = indexRight;
            indexRight += 1;
            break;
        case UP:
            static int indexUp = indicesPerSet * 3;
            indexUp = boundValue(indexUp, indicesPerSet * 3, indicesPerSet * 4);
            currentAnimIndex = indexUp;
            indexUp += 1;
            break;
    }
}

void SpriteSheet::updateCurrentClip(){
    currentClip = {ssTilePos.at(walkCycleIndices.at(currentAnimIndex)).x, ssTilePos.at(walkCycleIndices.at(currentAnimIndex)).y,
                    tileSizeX, tileSizeY};
}

void SpriteSheet::render(int pos_x, int pos_y){
    Texture.render(pos_x, pos_y, &currentClip);
}