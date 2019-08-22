#include <Map.h>

Player* Map::player = NULL;

Map::Map(){
    
}

void Map::loadMapFromJson(std::string jsonPath, std::string tileImgPath){
    std::ifstream tmpFile(jsonPath);
    json mapJsonFormat;
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
                                newLayer.tile_data.push_back(it.value()[j]);
                            }
                        }else if(it.key() == "type"){
                            newLayer.type = it.value();
                        }else if(it.key() == "objects"){
                            for(int objCount=0; objCount < it.value().size(); objCount++){
                                if(it.value().at(objCount)["name"] == "Wall"){
                                    Wall tmpWall({it.value().at(objCount)["x"], it.value().at(objCount)["y"],
                                        it.value().at(objCount)["width"], it.value().at(objCount)["height"]}); 
                                    MapWalls.push_back(tmpWall);
                                }
                            }
                        }
                    }
                    layers.push_back(newLayer);
                }
            }       
        }
        mapRect = {0, 0, WIDTH*TILEWIDTH, HEIGHT*TILEWIDTH};
        tmpFile.close();
        mapJsonFormat.clear();
    }
    mapTilesImage.loadSheet(tileImgPath, TILEWIDTH, TILEWIDTH);
}


void Map::render(Camera* camera, Player* player){
    SDL_Rect mapNewRect = camera->apply(mapRect);
    for(int layerCount=0; layerCount<layers.size(); layerCount++){
            pos_x_counter = mapNewRect.x;
            pos_y_counter = mapNewRect.y;  

        if(layers.at(layerCount).type == "objectgroup"){
            player->render(camera->apply(player->getRect()));
            for(int i=0; i<MapWalls.size(); i++){
                SDL_Rect tmpRect = camera->apply(MapWalls.at(i).getRect());
                MapWalls.at(i).render(tmpRect.x, tmpRect.y);
            }
        }else if(layers.at(layerCount).type == "tilelayer"){
            for(int tileCount=0; tileCount<layers.at(layerCount).tile_data.size(); tileCount++){
                tileIndex = layers.at(layerCount).tile_data[tileCount] - 1;
                if(tileIndex != -1){
                    mapTilesImage.setFocusTile(tileIndex);
                    mapTilesImage.render(pos_x_counter, pos_y_counter);
                }
                pos_x_counter+=TILEWIDTH;
                if(pos_x_counter == TILEWIDTH*layers.at(layerCount).width + mapNewRect.x){
                    pos_x_counter = mapNewRect.x;
                    pos_y_counter += TILEWIDTH;
                }   
            }
        }
    }
}

void Map::events(){

}

void Map::setPlayerSpawnPoint(int toX, int toY){
    player->getRectPtr()->x = mapRect.x + toX;
    player->getRectPtr()->y = mapRect.y + toY;
}

SDL_Rect Map::getMapRect(){
    return mapRect;
}


void Map::grantPlayerInfo(Player &player){
    player.mapWalls = &MapWalls;
}

void Map::setPlayerAdress(Player *playerMem){
    player = playerMem;
}