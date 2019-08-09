#include <Game.h>

Game::Game(){

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
}

void Game::mainLoop(){
    while( SDL_PollEvent(&events) != 0){
        if( events.type == SDL_QUIT){
            exit_status = true;
        }
    }
}