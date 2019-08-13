#include <Player.h>

Player::Player(SDL_Rect Rect){
    this->pRect = Rect;
}

void Player::render(){
    canvas();
}

void Player::events(SDL_Event &event){
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP:
                pRect.y -= movementSpeed;
                break;
            case SDLK_DOWN:
                pRect.y += movementSpeed;
                break;
            case SDLK_LEFT:
                pRect.x -= movementSpeed;
                break;
            case SDLK_RIGHT:
                pRect.x += movementSpeed;
                break;
        }
    }
}

SDL_Rect* Player::getRectPtr(){
    return &pRect;
}

void Player::canvas(){
    pCanvas.drawRect(pRect, BLUE);
}
