#include <Player.h>

Player::Player(SDL_Rect Rect){
    this->pRect = Rect;
    //this->rRect = Rect;
}

void Player::render(){
    canvas();
}

void Player::events(SDL_Event &event){
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP:
                pRect.y -= movementSpeed;
                //rRect.y -= movementSpeed;
                break;
            case SDLK_DOWN:
                pRect.y += movementSpeed;
                //rRect.y += movementSpeed;
                break;
            case SDLK_LEFT:
                pRect.x -= movementSpeed;
                //rRect.x -= movementSpeed;
                break;
            case SDLK_RIGHT:
                pRect.x += movementSpeed;
                //rRect.x += movementSpeed;
                break;
            default:
                std::cout << "x: "<< pRect.x << " y: " << pRect.y << std::endl;
        }
    }
}

SDL_Rect* Player::getRectPtr(){
    return &pRect;
}

SDL_Rect Player::getRect(){
    return pRect;
}

//SDL_Rect* Player::getRenderRectPtr(){
//    return &rRect;
//}

void Player::canvas(){
    static SDL_Rect rect = {SCREEN_WIDTH/2, SCREEN_HEIGHT/2, TILESIZE, TILESIZE*2};
    pCanvas.drawRect(&rect, BLUE);
}
