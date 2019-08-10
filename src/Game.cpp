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

void Game::render(){
    setRenderDrawColor(chooseColor(WHITE));
    SDL_RenderClear(gRenderer);

    drawRect(gRenderer, {0, 0, 200, 200}, chooseColor(GREEN));

    SDL_RenderPresent(gRenderer);
}

void Game::mainLoop(){
    events();
    render();
}

void Game::events(){
    while( SDL_PollEvent(&event) != 0 ){
        if( event.type == SDL_QUIT){
            close();
        }
    }
}

void Game::setRenderDrawColor(SDL_Color color){
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
}

void Game::close(){
    exit_status = true;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}