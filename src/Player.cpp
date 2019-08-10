#include <Player.h>

Player::Player(SDL_Rect Rect){
    this->Rect = Rect;
}

SDL_Rect Player::getRect(){
    return Rect;
}