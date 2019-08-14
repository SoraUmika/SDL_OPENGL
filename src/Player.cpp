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
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP:
                pRect.y -= movementSpeed;
                pos_y -= movementSpeed;
                break;
            case SDLK_DOWN:
                pRect.y += movementSpeed;
                pos_y += movementSpeed;
                break;
            case SDLK_LEFT:
                pRect.x -= movementSpeed;
                pos_x -= movementSpeed;
                break;
            case SDLK_RIGHT:
                pRect.x += movementSpeed;
                pos_x += movementSpeed;
                break;
            default:
                std::cout << "player x: "<< pRect.x << " y: " << pRect.y << std::endl;
                std::cout << "offSetRect x: "<< camRect.x << " offSetRect y: " << camRect.y << std::endl;
                //std::cout << "render x: "<< tmpRect.x << " render y: " << tmpRect.y << std::endl;
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

int Player::getPos_x(){
    return pos_x;
}

int Player::getPos_y(){
    return pos_y;
}