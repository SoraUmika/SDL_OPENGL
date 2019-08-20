#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include <SDL.h>

enum SpriteType{PLAYER, NPC, WALL, ITEM};

class Sprite{
    public:
    
    protected:
        SDL_Rect m_rect;
        SpriteType m_type;
    private:

};

#endif