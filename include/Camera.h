#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SDL.h>
#include <Player.h>
#include <Root.h>

struct Offset{
    int x;
    int y;
};

class Camera: public Root{
    public:
        void init(int width, int height);
        SDL_Rect apply(SDL_Rect entityRect);
        void update(SDL_Rect target);
        
    private:
        SDL_Rect cameraRect;
        int cam_x;
        int cam_y;
        int mapWidth;
        int mapHeight;

};

#endif