#include <Player.h>

Player::Player(int x, int y, int width, int heigh){
    pRect = {x, y, width, heigh};
    //this->rRect = Rect;
}

void Player::events(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ] ){
        pRect.y -= movementSpeed;
        animation(UP);
    }else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){
        pRect.y += movementSpeed;
        animation(DOWN);
    }else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        pRect.x -= movementSpeed;
        animation(LEFT);
    }else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        pRect.x += movementSpeed;
        animation(RIGHT);
    }
    if( currentKeyStates[ SDL_SCANCODE_X ]){
        movementSpeed = 4;
    }else{
        movementSpeed = 2;
    }
    
}

void Player::animation(Direction direction){
    if(SDL_GetTicks()-previousTick > 100){
        previousTick = SDL_GetTicks();
        switch(direction){
            case DOWN:  
                pSS.setCurrentClip(DOWN);
                break;
            case UP:
                pSS.setCurrentClip(UP);          
                break;
            case LEFT:
                pSS.setCurrentClip(LEFT);
                break;
            case RIGHT:
                pSS.setCurrentClip(RIGHT);
                break;
        }
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

void Player::load_ss(std::string path){
    pSS.loadSheet(path, 32);
    pSS.loadAnimTileSet({"down", {0, 1, 2}}, {"left", {12, 13, 14}}, {"right", {24, 25, 26}}, {"up", {36, 37, 38}});
    std::cout << pSS.walkCycleLeft.at(0).x << std::endl;
    std::cout << pSS.walkCycleLeft.at(0).y << std::endl;
}

void Player::render(SDL_Rect cameraRect){
    camRect = cameraRect;
    tmpRect = {cameraRect.x, cameraRect.y, TILESIZE,  TILESIZE*2};
    pCanvas.drawRect(&tmpRect, BLUE);
    
    pSS.Texture.render(cameraRect.x, cameraRect.y, &pSS.currentClip);
    
    //canvas();
}