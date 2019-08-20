#include <Camera.h>

void Camera::init(int width, int height){
    cameraRect = {0, 0, mapWidth, mapHeight};
    mapWidth = width;
    mapHeight = height;
}

SDL_Rect Camera::apply(SDL_Rect entityRect){
    return {cameraRect.x+entityRect.x, cameraRect.y+entityRect.y, entityRect.w, entityRect.h};
}

void Camera::update(SDL_Rect target){
    cameraRect = {-target.x + (SCREEN_WIDTH/2), -target.y + (SCREEN_HEIGHT/2), mapWidth, mapHeight};
}
