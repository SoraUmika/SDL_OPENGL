#ifndef SPRITESHEET_H_INCLUDEDS
#define SPRITESHEET_H_INCLUDEDS

#include <iostream>
#include <LTexture.h>
#include <vector>
#include <SDL.h>
#include <string>
#include <utility.h>
struct TilePosition{
    int x;
    int y;
};

class SpriteSheet{
    public:
        LTexture Texture;

        //each tile's position relative to the spritesheet
        std::vector<TilePosition> tilePositions;

        void loadSheet(std::string path, int tileSizeX, int tileSizeY);
        void render(int pos_x, int pos_y);

        //set focus tile base on tile index , count starting from left to down
        void setFocusTile(int tileIndex);

    private:
        int spriteSheetWidth;
        int spriteSheetHeight;
        
        SDL_Rect focusedTileClip;
        int tileSizeX;
        int tileSizeY;
        int indicesPerSet;
        void parseSheet();

};

#endif