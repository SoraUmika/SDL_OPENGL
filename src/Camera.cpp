#include <Camera.h>

void Camera::init(int width, int height){
    cameraRect = {0, 0, mapWidth, mapHeight};
    mapWidth = width;
    mapHeight = height;
}

SDL_Rect Camera::apply(SDL_Rect entityRect){
    return {entityRect.x + cameraRect.x, entityRect.y + cameraRect.y};
}

void Camera::update(SDL_Rect target){
    offSet_x = -target.x + (SCREEN_WIDTH/2);
    offSet_y = -target.y + (SCREEN_HEIGHT/2);
    cameraRect = {offSet_x, offSet_y, mapWidth, mapHeight};
}

SDL_Rect Camera::takeRect(){
    return {offSet_x, offSet_y, mapWidth, mapHeight};
}