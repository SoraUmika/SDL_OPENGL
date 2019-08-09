#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <Game.h>

using namespace std;

int main(int argv, char** args){

    Game gameApp = Game();

    while(!gameApp.exit_status){
        gameApp.mainLoop();
    }
    return 0;   
}       