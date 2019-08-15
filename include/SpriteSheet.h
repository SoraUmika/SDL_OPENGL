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
    std::vector<tilePos> animTilePos;
};

struct AnimSet{
    std::string type;
    std::vector<int> tileIndices;
};

class SpriteSheet{
    public:
        LTexture Texture;
        std::vector<tilePos> ssTilePos;

        void loadSheet(std::string path, int tileSize);
        
        void loadAnimTileSet(AnimSet down, AnimSet left, AnimSet right, AnimSet up);

        std::vector<tilePos> walkCycleLeft;
        std::vector<tilePos> walkCycleRight;
        std::vector<tilePos> walkCycleUp;
        std::vector<tilePos> walkCycleDown;
        int indexDown = 0;
        int indexUp = 0;
        int indexLeft = 0;
        int indexRight = 0;


        void setCurrentClip(Direction direction);
        int currentAnimIndex;
        SDL_Rect currentClip;
        int sheetSize_x;
        int sheetSize_y;
    private:
        int tileSize;
        void parseSheet();

};

#endif