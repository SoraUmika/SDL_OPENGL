#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include <vector>
#include <iostream>
template <class VAR> class Specicialized_V{
    public:
        Specicialized_V(){};
        Specicialized_V(int reserve_amt){
            m_vector.reserve(reserve_amt);
        }

        VAR at(int index){
            return m_vector.at(index);
        }
        void reserve(int reserve_amt){
            m_vector.reserve(reserve_amt);
        }
        void push_back(VAR value){
            m_vector.push_back(value);
        }

        VAR next(){
            currentIndex ++;
            if(currentIndex == m_vector.size()){
                currentIndex = 0;
            }
            std::cout << "index: " << currentIndex << std::endl;
            return m_vector.at(currentIndex);
        }        
    private:
        std::vector<VAR> m_vector;
        int currentIndex = 0;
};
#endif