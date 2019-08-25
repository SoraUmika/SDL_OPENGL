#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include <vector>
#include <iostream>
template <class T> 
class ControlledVector{
    public:
        void setVector(std::vector<T> vectorList){
            container = vectorList;
        }
        int next(){
            currentIndex++;
            if(currentIndex == container.size()){
                currentIndex = 0;
            }
            return container.at(currentIndex);
        }
    private:
        std::vector<T> container;
        int currentIndex = 0;
};
#endif