#include <Game.h>

Game::Game(){
    if(SDL_Init( SDL_INIT_VIDEO ) < 0){
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
    }else{
        gWindow = SDL_CreateWindow("SDL_OPENGL", SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(gWindow == NULL){
            std::cout << "Windows cannot be intialized! SDL Error: " << SDL_GetError() << std::endl;
        }else{
            gWindowSurface = SDL_GetWindowSurface( gWindow );

            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gRenderer == NULL){
                std::cout << "SDL render fail to initialize" << SDL_GetError() << std::endl;
            }else{
                int imgFlags = IMG_INIT_PNG;
                if( !(IMG_Init(imgFlags) & imgFlags) ){
                    std::cout << "SDL_image could not initialize! SDL_iamge Error: " << IMG_GetError() << std::endl;
                }     

                if( TTF_Init() == -1){
                    std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl; 
                }
                defaultFont = loadFont("assets/font/ostrich-regular.ttf", 24);
                initBasicObject();
            }
        }
    }
}

void Game::render(){
    setRenderDrawColor(chooseColor(WHITE));
    SDL_RenderClear(gRenderer);

    player.render();
    //drawRect(gRenderer, {0, 0, 200, 200}, chooseColor(GREEN));
    displayFPS();

    SDL_RenderPresent(gRenderer);
}

void Game::mainLoop(){
    render();
    events(inGame);
}

void Game::events(appStatus status){
    while( SDL_PollEvent(&event) != 0 ){
        if( event.type == SDL_QUIT){
            close();
        }
        switch(status){
            case inGame:
                player.events(event);
        }
    }
}

void Game::close(){
    exit_status = true;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

void Game::initBasicObject(){
    fpsCount = 0;
    timeTicks = 0;
    fpsRect = {5, 5, 100, 24};
    fpsTextTexture = loadTextTexture(defaultFont, to_string(fpsCount), {0, 0, 0, 255});
}

void Game::displayFPS(){
    if((SDL_GetTicks()-timeTicks) >= 1000){
        timeTicks = SDL_GetTicks();
        fpsTextTexture = loadTextTexture(defaultFont, to_string(fpsCount), {0, 0, 0, 255});
        fpsCount = 0;
    }
    SDL_RenderCopy(gRenderer, fpsTextTexture, NULL, &fpsRect);
    fpsCount++;
}