#include <Map.h>

Map::Map(){
    
}

void Map::convertStringToInt(std::string stringVal){

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
                        }
                    }
                    layers.push_back(newLayer);
                }
            }
        }
    }
    tileSet.loadSheet(tileImgPath, TILEWIDTH);
}

void Map::setRenderPos(int x, int y){
    mapPos_x = x;
    mapPos_y = y;
}

void Map::render(){
    static bool flag = false;
    for(int layerCount=0; layerCount<layers.size(); layerCount++){
            pos_x_counter = mapPos_x;
            pos_y_counter = mapPos_y;
        for(int tileCount=0; tileCount<layers.at(layerCount).data.size(); tileCount++){
            tileIndex = layers.at(layerCount).data[tileCount] - 1;
            if(tileIndex != -1){
                renderClip = {tileSet.tilePos.at(tileIndex).x, tileSet.tilePos.at(tileIndex).y, TILEWIDTH, TILEWIDTH};
                tileSet.sheetTexture.render(pos_x_counter, pos_y_counter, &renderClip);
                if(!flag){
                }
            }


            pos_x_counter+=TILEWIDTH;
            if(pos_x_counter == TILEWIDTH*layers.at(layerCount).width + mapPos_x){
                pos_x_counter = mapPos_x;
                pos_y_counter += TILEWIDTH;
            }
            
        }
    }
    flag = true;
}

void Map::setPlayerSpawnPoint(SDL_Rect *playerRect){
    playerRect->x = mapPos_x;
    playerRect->y = mapPos_y;
}