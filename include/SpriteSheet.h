#ifndef SPRITESHEET_H_INCLUDEDS
#define SPRITESHEET_H_INCLUDEDS

#include <iostream>
#include <LTexture.h>
#include <vector>
#include <SDL.h>
#include <string>
#include <utility.h>
struct tilePos{
    int x;
    int y;
};

struct aaTilepos{
    std::string direction;
    std::vector<int> tileIndices;
};

//select sprite tile indices
struct AnimSet{
    std::string type;
    std::vector<Uint16> tileIndices;
};

class SpriteSheet{
    public:
        LTexture Texture;
        std::vector<tilePos> ssTilePos;

        void loadSheet(std::string path, int tileSizeX, int tileSizeY);
        
        void loadAnimTileSet(AnimSet down, AnimSet left, AnimSet right, AnimSet up);

        void render(int pos_x, int pos_y);
        std::vector<int> walkCycleIndices;
        int currentAnimIndex = 0;

        void setCurrentClip(Direction direction);

        void updateCurrentClip();
        SDL_Rect currentClip;
        int sheetSize_x;
        int sheetSize_y;
    private:
        int tileSizeX;
        int tileSizeY;
        int indicesPerSet;
        void parseSheet();

};

#endif