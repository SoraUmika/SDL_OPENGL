#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <vector>
#include <json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;

struct layer{
    int width = 0;
    int height = 0;
    std::string name;

};

class Map{
    public:
        Map();
        
        void loadMapFromJson();
        void render();

        std::vector<layer> layers;
    private:
    
        int TILEWIDTH;
        int WIDTH;
        int HEIGHT;
        int convertStringToInt(std::string stringVal);

        json mapJsonFormat;
        void loadJson(std::string path);

};

#endif