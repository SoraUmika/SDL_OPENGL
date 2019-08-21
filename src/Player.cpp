#include <Player.h>

Player::Player(int x, int y, int width, int heigh){
    m_rect = {x, y, width, heigh};
}

void Player::events(){
    keyEvents();
}

void Player::keyEvents(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ] ){
        m_rect.y -= movementSpeed;
        animation(MOVE_UP);
    }else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){
        m_rect.y += movementSpeed;
        animation(MOVE_DOWN);
    }else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        m_rect.x -= movementSpeed;
        animation(MOVE_LEFT);
    }else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        m_rect.x += movementSpeed;
        animation(MOVE_RIGHT);
    }
    else if( currentKeyStates[ SDL_SCANCODE_SPACE ]){
        std::cout << m_rect.x << " :" << m_rect.y << " :" << std::endl;
    }
    if( currentKeyStates[ SDL_SCANCODE_X ]){
        movementSpeed = 4;
    }else{
        movementSpeed = 2;
    }

}

void Player::animation(AnimeType animeType){
    switch(animeType){
        case MOVE_DOWN:
            playerTiles.setFocusTile(0);
            break;
        case MOVE_LEFT:
            playerTiles.setFocusTile(12);
            break;
        case MOVE_RIGHT:
            playerTiles.setFocusTile(24);
            break;
        case MOVE_UP:
            playerTiles.setFocusTile(36);
            break;
        case STAND_BY:
            
    }
}

SDL_Rect* Player::getRectPtr(){
    return &m_rect;
}

void Player::canvas(){
    pCanvas.drawRect(&m_rect, BLUE);
}

void Player::loadSpriteSheet(std::string path){
    playerTiles.loadSheet(path, 32, 32);
}

void Player::render(SDL_Rect renderRect){
    playerTiles.render(renderRect.x, renderRect.y);    
}