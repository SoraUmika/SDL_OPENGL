#ifndef SPRITESHEET_H_INCLUDEDS
#define SPRITESHEET_H_INCLUDEDS

#include <iostream>
#include <LTexture.h>
#include <vector>
#include <SDL.h>
#include <string>

struct tilePos{
    int x;
    int y;
};

class SpriteSheet{
    public:
        LTexture sheetTexture;
        std::vector<tilePos> tilePos;

        void loadSheet(std::string path, int tileSize);
         
        int sheetSize_x;
        int sheetSize_y;
    private:
        int tileSize;
        void parseSheet();

};

#endif