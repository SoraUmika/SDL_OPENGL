#include <Camera.h>

void Camera::init(int width, int height){
    cameraRect = {0, 0, mapWidth, mapHeight};
    mapWidth = width;
    mapHeight = height;
}

void Camera::apply(SDL_Rect *entityRect){
    entityRect->x = offSet_x;
    entityRect->y = offSet_y;
}

void Camera::update(SDL_Rect targetRect){
    offSet_x = -targetRect.x + SCREEN_WIDTH /2;
    offSet_y = -targetRect.y + SCREEN_HEIGHT /2;
}