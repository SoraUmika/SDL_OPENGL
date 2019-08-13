#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <vector>
#include <json.hpp>
#include <fstream>
#include <string>
#include <LTexture.h>

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
        
        void loadMapFromJson(std::string path);
        void render();

        std::vector<layer> layers;
    private:
    
        int TILEWIDTH;
        int WIDTH;
        int HEIGHT;
        void convertStringToInt(std::string stringVal);

        json mapJsonFormat;

};

#endif