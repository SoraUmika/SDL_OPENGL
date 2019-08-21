#include <SpriteSheet.h>

void SpriteSheet::loadSheet(std::string path, int tileSizeX, int tileSizeY){
    this->tileSizeX = tileSizeX;
    this->tileSizeY = tileSizeY;
    Texture.loadTextureFromFile(path);
    Texture.retrieveSize(&spriteSheetWidth, &spriteSheetHeight);
    if(spriteSheetWidth == 0 || spriteSheetWidth == 0){
          std::cout << "Sprite Sheet not initialize properly!" << std::endl;
    }else{
        parseSheet();
    }
}

void SpriteSheet::parseSheet(){
    //should reserve memory
    for(int j=0; j<spriteSheetHeight; j+=tileSizeY){
        for(int i=0; i<spriteSheetWidth; i+=tileSizeX){
            tilePositions.push_back({i, j});
        }
    }
    focusedTileClip = {tilePositions.at(0).x, tilePositions.at(0).y, tileSizeX, tileSizeY};
}

void SpriteSheet::render(int pos_x, int pos_y){
    Texture.render(pos_x, pos_y, &focusedTileClip);
}

void SpriteSheet::setFocusTile(int index){
    focusedTileClip = {tilePositions.at(index).x, tilePositions.at(index).y, tileSizeX, tileSizeY};
}