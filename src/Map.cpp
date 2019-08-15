#include <Map.h>

Map::Map(){
    
}

void Map::loadMapFromJson(std::string jsonPath, std::string tileImgPath){
    std::ifstream tmpFile(jsonPath);
    tmpFile >> mapJsonFormat;
    if(mapJsonFormat.empty()){
        std::cout << "Unable to load json file from " << jsonPath << "! Perhaps Empty?" << std::endl;
    }else{
        for (json::iterator it = mapJsonFormat.begin(); it != mapJsonFormat.end(); ++it) {
            if(it.key() == "height"){
                HEIGHT = it.value();
            }else if(it.key() == "width"){
                WIDTH = it.value();
            }else if(it.key() == "tilewidth"){
                TILEWIDTH = it.value();
            }else if(it.key() == "layers"){
                for(int i=0; i<mapJsonFormat["layers"].size(); i++){
                    layer newLayer;
                    for (json::iterator it = mapJsonFormat["layers"][i].begin(); it != mapJsonFormat["layers"][i].end(); ++it){
                        if(it.key() == "width"){
                            newLayer.width = it.value();
                        }else if(it.key() == "height"){
                            newLayer.height = it.value();
                        }else if(it.key() == "name"){
                            newLayer.name = it.value();
                        }else if(it.key() == "data"){
                            for(int j = 0; j < it.value().size(); j++){
                                newLayer.data.push_back(it.value()[j]);
                            }
                        }else if(it.key() == "type"){
                            newLayer.type == it.value();
                        }
                    }
                    layers.push_back(newLayer);
                }
            }       
        }
        mapRect = {0, 0, WIDTH*TILEWIDTH, HEIGHT*TILEWIDTH};
        tmpFile.close();
        mapJsonFormat.clear();
        std::cout << layers.at(0).name << std::endl;

    }
    tileSet.loadSheet(tileImgPath, TILEWIDTH);
}


void Map::render(Camera camera, Player player){
    static bool tmpBool = false;
    SDL_Rect mapNewRect = camera.apply(mapRect);
    for(int layerCount=0; layerCount<layers.size(); layerCount++){
            pos_x_counter = mapNewRect.x;
            pos_y_counter = mapNewRect.y;

        if(layers.at(layerCount).name == "player"){
            player.render(camera.apply(player.getRect()));
        }
        
        for(int tileCount=0; tileCount<layers.at(layerCount).data.size(); tileCount++){
            tileIndex = layers.at(layerCount).data[tileCount] - 1;
            if(tileIndex != -1){
                renderClip = {tileSet.tilePos.at(tileIndex).x, tileSet.tilePos.at(tileIndex).y, TILEWIDTH, TILEWIDTH};
                tileSet.sheetTexture.render(pos_x_counter, pos_y_counter, &renderClip);
            }
            pos_x_counter+=TILEWIDTH;
            if(pos_x_counter == TILEWIDTH*layers.at(layerCount).width + mapNewRect.x){
                pos_x_counter = mapNewRect.x;
                pos_y_counter += TILEWIDTH;
            }   
        }
    }
}

void Map::renderEntity(SDL_Rect targetRect){
    canvas.drawRect(&targetRect, BLUE);
}

void Map::setPlayerSpawnPoint(SDL_Rect *playerRect, int toX, int toY){
    playerRect->x = mapRect.x + toX;
    playerRect->y = mapRect.y + toY;
}

void Map::setMapPos(int x, int y){
    mapRect.x = x;
    mapRect.y = y;
}

SDL_Rect Map::getMapRect(){
    return mapRect;
}

SDL_Rect* Map::getMapRectPtr(){
    return &mapRect;
}