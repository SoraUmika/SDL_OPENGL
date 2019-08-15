#include <Player.h>

Player::Player(int x, int y, int width, int heigh){
    pRect = {x, y, width, heigh};
    //this->rRect = Rect;
}

void Player::render(SDL_Rect cameraRect){
    camRect = cameraRect;
    tmpRect = {cameraRect.x, cameraRect.y, TILESIZE,  TILESIZE*2};
    pCanvas.drawRect(&tmpRect, BLUE);
    //canvas();
}

void Player::events(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ] ){
        pRect.y -= movementSpeed;
    }else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){
        pRect.y += movementSpeed;
    }else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        pRect.x -= movementSpeed;
    }else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        pRect.x += movementSpeed;
    }
    if( currentKeyStates[ SDL_SCANCODE_X ]){
        movementSpeed = 4;
    }else{
        movementSpeed = 2;
    }
    
}

SDL_Rect* Player::getRectPtr(){
    return &pRect;
}

SDL_Rect Player::getRect(){
    return pRect;
}

void Player::canvas(){
    pCanvas.drawRect(&pRect, BLUE);
}

void Player::load_texture(std::string path){
    pTextureList.loadSheet(path, 32);
    std::cout << pTextureList.sheetSize_x << std::endl;
    std::cout << pTextureList.tilePos.at(1).x << std::endl;
}