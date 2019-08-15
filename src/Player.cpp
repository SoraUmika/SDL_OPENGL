#include <Player.h>

Player::Player(int x, int y, int width, int heigh){
    pRect = {x, y, width, heigh};
    pos_x = x;
    pos_y = y;
    //this->rRect = Rect;
}

void Player::render(SDL_Rect cameraRect){
    camRect = cameraRect;
    tmpRect = {cameraRect.x, cameraRect.y, TILESIZE,  TILESIZE*2};
    pCanvas.drawRect(&tmpRect, BLUE);
    //canvas();
}

void Player::events(SDL_Event &event){
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

int Player::getPos_x(){
    return pos_x;
}

int Player::getPos_y(){
    return pos_y;
}