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
    cam_x = -target.x + (SCREEN_WIDTH/2);
    cam_y = -target.y + (SCREEN_HEIGHT/2);

    cam_x = getMinVal(0, cam_x);
    cam_y = getMinVal(0, cam_y);
    cam_x = getMaxVal(-(mapWidth - SCREEN_WIDTH), cam_x);
    cam_y = getMaxVal(-(mapHeight - SCREEN_HEIGHT), cam_y);
    cameraRect = {cam_x, cam_y, mapWidth, mapHeight};

}
