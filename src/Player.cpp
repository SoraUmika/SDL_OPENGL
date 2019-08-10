#include <Player.h>

Player::Player(SDL_Rect Rect){
    this->Rect = Rect;
}

SDL_Rect Player::getRect(){
    return Rect;
}

void Player::events(SDL_Event &event){
    //handled in Game.cpp
    if(event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym){
            case SDLK_UP:
                this->Rect.y -= movementSpeed;
                break;
            case SDLK_DOWN:
                this->Rect.y += movementSpeed;
                break;
            case SDLK_LEFT:
                this->Rect.x -= movementSpeed;
                break;
            case SDLK_RIGHT:
                this->Rect.x += movementSpeed;

        }
    }
}

void Player::render(){
    drawRect(gRenderer, Rect, chooseColor(BLUE));
}
