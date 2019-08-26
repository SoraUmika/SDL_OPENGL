#include <Player.h>

Player::Player(int x, int y, int width, int height){
    m_rect = {x, y, width, height};
    moveDownIndices.setVector({0, 1, 2});
    moveLeftIndices.setVector({12, 13, 14});
    moveRightIndices.setVector({24, 25, 26});
    moveUpIndices.setVector({36, 37, 38});
}

void Player::events(){
    keyEvents();
}

void Player::keyEvents(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ] ){
        if(!collide_with_walls(0, -movementSpeed)){
            m_rect.y -= movementSpeed;
        }
        animation(MOVE_UP);
    }else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ){
        if(!collide_with_walls(0, movementSpeed)){
            m_rect.y += movementSpeed;
        }   
        animation(MOVE_DOWN);
    }else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ){
        if(!collide_with_walls(-movementSpeed, 0)){
            m_rect.x -= movementSpeed;
        }
        animation(MOVE_LEFT);
    }else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ){
        if(!collide_with_walls(movementSpeed, 0)){
            m_rect.x += movementSpeed;
        }
        animation(MOVE_RIGHT);
    }else{
        animation(STAND_BY);
    }
    if( currentKeyStates[ SDL_SCANCODE_SPACE ]){
        std::cout << m_rect.x << " :" << m_rect.y << " :" << std::endl;
    }
    if( currentKeyStates[ SDL_SCANCODE_X ]){
        timerWaitTime = 100;
        movementSpeed = 4;
    }else{
        movementSpeed = 2;
        timerWaitTime = 200;
    }
}

void Player::animation(AnimeType animeType){
    switch(animeType){
        case MOVE_DOWN:
            previousMove = DOWN;
            if(moveDownTimer.checkTimePassed(timerWaitTime)){
                playerTiles.setFocusTile(moveDownIndices.next());
            }
            break;
        case MOVE_LEFT:
            previousMove = LEFT;
            if(moveLeftTimer.checkTimePassed(timerWaitTime)){
                playerTiles.setFocusTile(moveLeftIndices.next());
            }
            break;
        case MOVE_RIGHT:
            previousMove = RIGHT;
            if(moveRightTimer.checkTimePassed(timerWaitTime)){
                playerTiles.setFocusTile(moveRightIndices.next());        
            }
            break;
        case MOVE_UP:
            previousMove = UP;
            if(moveUpTimer.checkTimePassed(timerWaitTime)){
                playerTiles.setFocusTile(moveUpIndices.next());
            }
            break;
        case STAND_BY:
            switch(previousMove){
                case DOWN:
                    playerTiles.setFocusTile(1);
                    break;
                case LEFT:
                    playerTiles.setFocusTile(13);
                    break;
                case RIGHT:
                    playerTiles.setFocusTile(25);
                    break;
                case UP:
                    playerTiles.setFocusTile(37);
            }           
    }
}   

SDL_Rect* Player::getRectPtr(){
    return &m_rect;
}

void Player::canvas(){
    pCanvas.drawRect(&m_rect, BLUE);
}

void Player::loadSpriteSheet(std::string path){
    playerTiles.loadSheet(path, 32, 48);
}

void Player::render(SDL_Rect renderRect){
    playerTiles.render(renderRect.x, renderRect.y-16);    
}

bool Player::collide_with_walls(int dx, int dy){
    for(int i=0; i<mapWalls->size();i++){
        SDL_Rect playerTempNewRect = {m_rect.x + dx, m_rect.y + dy, m_rect.w, m_rect.h};
        if(isCollision(playerTempNewRect, mapWalls->at(i).getRect())){
            return true;
        }
    }
    return false;
}