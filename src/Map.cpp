#include <Map.h>

Map::Map(){
    
}

int Map::convertStringToInt(std::string stringVal){

}


void Map::loadJson(std::string path){
    std::ifstream tmpFile(path);
    tmpFile >> mapJsonFormat;
    if(mapJsonFormat.empty()){
        std::cout << "Unable to load json file from " << path << "! Perhaps Empty?" << std::endl;
    }

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