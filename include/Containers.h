#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include <vector>
#include <iostream>
template <class VAR> class Specicialized_V{
    public:
        Specicialized_V(){}
        Specicialized_V(int reserve_amt){
            m_vector.reserve(reserve_amt);
        }
        Specicialized_V(std::vector<VAR> vec){
            m_vector = vec;
        }
        void init(std::vector<VAR> vec){
            m_vector.reserve(vec.size());
            for(int i=0; i<vec.size(); i++){
                vec.push_back(vec.at(i));
            }
        }
        void reserve(int reserve_amt){
            m_vector.reserve(reserve_amt);
        }
        void push_back(VAR value){
            m_vector.push_back(value);
        }
        VAR at(int index){
            return m_vector.at(index);
        }
        VAR next(){
            currentIndex ++;
            if(currentIndex == m_vector.size()){
                currentIndex = 0;
            }
            return m_vector.at(currentIndex);
        }        
    private:
        std::vector<VAR> m_vector;
        int currentIndex = 0;
};
#endif