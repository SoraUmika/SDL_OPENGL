#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED

#include <iostream>
#include <SDL.h>
#include <Root.h>
#include <utility.h>

class Canvas: public Root{
    public:
        void drawGrid(int gridSize, enumColors color=BLACK);
        void drawRect(SDL_Rect *rect, enumColors Color=GREEN);
        void drawRectOutline(SDL_Rect *rect, enumColors Color=YELLOW);
    private:
};

#endif