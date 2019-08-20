#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <SDL.h>
#include <vector>
#include <string>
class simpleTimer{
    public:
        bool checkTimePassed(int interval){
            if(SDL_GetTicks()-m_timeTicks > interval){
                m_timeTicks = SDL_GetTicks();
                return true;
            }else{
                return false;
            }
        };     
    protected:
        int m_timeTicks = 0;

};

class dynamicTimer: public simpleTimer{
    public:
        void resetTimeTicks(){
            m_timeTicks = 0;
        };
        
        void setName(std::string TimerName){
            TimerName = m_name;
        }

        std::string getName(){
            return m_name;
        }
    private:    
        int m_timeTicks = 0;
        std::string m_name;
};

#endif