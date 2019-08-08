#include <iostream>
#include <SDL.h>
#include <stdio.h>
using namespace std;

int main(int argv, char** args){

    SDL_Window* gWindow = NULL;
    SDL_Surface* gWindowSurface = NULL;
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    //initialize SDL
    if(SDL_Init( SDL_INIT_VIDEO ) < 0){
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
    }else{
        gWindow = SDL_CreateWindow("SDL_OPENGL", SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(gWindow == NULL){
            cout << "Windows cannot be intialized! SDL Error: " << SDL_GetError() << endl;
        }else{
            gWindowSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return 0;   
}       