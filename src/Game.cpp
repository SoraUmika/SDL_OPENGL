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

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer == NULL){
                cout << "SDL render fail to initialize" << SDL_GetError() << endl;
            }
        }
    }
}

void Game::mainLoop(){
    Events();

}

void Game::Events(){
    while( SDL_PollEvent(&events) != 0){
        if( events.type == SDL_QUIT){
            exit_status = true;
        }
    }
}
