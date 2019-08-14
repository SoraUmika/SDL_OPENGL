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
        void apply(SDL_Rect *entityRect);
        void update(SDL_Rect targetRect);

        Offset offSet();
    private:
        SDL_Rect cameraRect;
        int mapWidth;
        int mapHeight;
        
        int offSet_x;
        int offSet_y;
};

#endif