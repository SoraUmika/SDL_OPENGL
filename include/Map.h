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
#include <Canvas.h>
#include <Player.h>
#include <Camera.h>
#include <Root.h>
#include <Sprite.h>
#include <utility>
using json = nlohmann::json;

struct layer{
    int width = 0;
    int height = 0;
    std::string type;
    std::string name;
    std::vector<int> tile_data;
};

class Map: public Root{
    public:
        Map();
        void loadMapFromJson(std::string jsonPath, std::string tileImgPath);
        void render(Camera* camera, Player* player);
        void events();
        
        void setPlayerSpawnPoint(int toX, int toY);
        void grantPlayerInfo(Player &player);
        SDL_Rect getMapRect();

        void setPlayerAdress(Player *playerMem);
        
    private:
        int TILEWIDTH;
        int WIDTH; //tile_width
        int HEIGHT;  //tile_height
        
        SDL_Rect mapRect; //mapRect in pixels
        SpriteSheet mapTilesImage;
        std::vector<layer> layers;

        Canvas canvas;

        static Player *player;  

        //render
        int tileIndex;
        int pos_x_counter;
        int pos_y_counter;
        std::vector<Wall> MapWalls;

        SDL_Rect renderClip;
};

#endif