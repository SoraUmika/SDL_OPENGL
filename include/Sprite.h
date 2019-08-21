#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include <SDL.h>
#include <map>
#include <string>
#include <iostream>
enum SpriteType{PLAYER, NPC, WALL, ITEM};

void tmpFunction();
class Sprite{
    public:
        virtual SDL_Rect getRect(){
            return m_rect;
        }
    protected:
        SDL_Rect m_rect;
        SpriteType m_type;
    private:

};

class Wall: public Sprite{
    public:
        Wall(SDL_Rect rect){
            m_type = WALL;
            m_rect = rect;
        }   
    private:

};

class Npc: public Sprite{
    public:
        Npc(SDL_Rect rect){
            m_type = NPC;
            m_rect = rect;
        }
    private:
};


#endif