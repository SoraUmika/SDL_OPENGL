#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <vector>
#include <json.hpp>
#include <fstream>
#include <string>
#include <LTexture.h>
#include <SpriteSheet.h>
using json = nlohmann::json;

struct layer{
    int width = 0;
    int height = 0;
    std::string name;
    std::vector<int> data;
};

class Map{
    public:
        Map();
        
        void loadMapFromJson(std::string jsonPath, std::string tileImgPath);
        void render();
        void setMapPos(int x, int y);
        void setPlayerSpawnPoint(SDL_Rect *playerRect, int toX, int toY);
        SDL_Rect getMapRect();
        SDL_Rect *getMapRectPtr();
        std::vector<layer> layers;
    private:
    
        int TILEWIDTH;
        int WIDTH; //tile_width
        int HEIGHT;  //tile_height
        
        SDL_Rect mapRect; //mapRect in pixels
        json mapJsonFormat;
        SpriteSheet tileSet;

        //render
        int tileIndex;
        int pos_x_counter;
        int pos_y_counter;

        SDL_Rect renderClip;
};

#endif