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
    renderPos_x = x;
    renderPos_y = y;
}

void Map::render(){
    //tileSet.sheetTexture.render(i*TILEWIDTH, j*TILEWIDTH, {});
    static bool flag = false;
    for(int layerCount=0; layerCount<layers.size(); layerCount++){
            pos_x_counter = renderPos_x;
            pos_y_counter = renderPos_y;
        for(int tileCount=0; tileCount<layers.at(layerCount).data.size(); tileCount++){
            tileIndex = layers.at(layerCount).data[tileCount] - 1;
            if(tileIndex != -1){
                renderClip = {tileSet.tilePos.at(tileIndex).x, tileSet.tilePos.at(tileIndex).y, TILEWIDTH, TILEWIDTH};
                tileSet.sheetTexture.render(pos_x_counter, pos_y_counter, &renderClip);
                if(!flag){
                    std::cout << "tile index " << tileIndex << " rendererd at " << pos_x_counter << ", " << pos_y_counter
                    << ". RectPos: " << renderClip.x << ", " << renderClip.h << std::endl;
                }
            }


            pos_x_counter+=TILEWIDTH;
            if(pos_x_counter == TILEWIDTH*layers.at(layerCount).width + renderPos_x){
                pos_x_counter = renderPos_x;
                pos_y_counter += TILEWIDTH;
            }
            
        }
    }
    flag = true;
}