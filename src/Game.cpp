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
                initGameObject();
            }
        }
    }
}

void Game::initGameObject(){
    defaultFont = loadFont("assets/font/ostrich-regular.ttf", 24);
    fpsTextTexture.loadTextTexture(defaultFont, to_string(fpsCount), {0, 0, 0, 255});
    fpsTextTexture.setTextureSize(80, 20);

    currentMap.loadMapFromJson("assets\\maps\\mageTown.json", "assets\\maps\\Tile_Set\\mageCity.png");
    currentMap.setPlayerSpawnPoint(player.getRectPtr(), TILESIZE*10, TILESIZE*10);

    player.loadSpriteSheet("assets\\spriteSheet\\characters\\characterList.png");

    camera.init(currentMap.getMapRect().w, currentMap.getMapRect().h);
}

void Game::render(){
    setRenderDrawColor(chooseColor(WHITE));
    SDL_RenderClear(gRenderer);

    currentMap.render(camera, player);

    displayFPS();
    SDL_RenderPresent(gRenderer);
}

void Game::mainLoop(){
    render();
    keyEvents();
    cameraEvents();
}

void Game::keyEvents(){
    player.events();
    
    while( SDL_PollEvent(&event) != 0 ){
        
        switch(appStatus){
            case inGame:
                break;
                
        }
        if( event.type == SDL_QUIT){
            close();
        }else if(event.type == SDL_KEYDOWN){
            switch(event.key.keysym.sym){
                case SDLK_F11:
                    if(!fullScreenFlag){
                        SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN_DESKTOP);
                        fullScreenFlag = true;
                    }else{
                        SDL_SetWindowFullscreen(gWindow, 0);
                        fullScreenFlag = false;
                    }
                    break;
                case SDLK_F4 && SDLK_LALT:
                    close();
                    break;
            }
        }
    }
}

void Game::cameraEvents(){
    camera.update(player.getRect());
}

void Game::close(){
    exit_status = true;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

void Game::displayFPS(){
    if(m_timer.checkTimePassed(1000)){
        fpsTextTexture.loadTextTexture(defaultFont, to_string(fpsCount), {0, 0, 0, 255});
        fpsCount = 0;
    }

    //SDL_RenderCopy(gRenderer, fpsTextTexture.getTexture(), NULL, &fpsRect);
    fpsTextTexture.render(5, 5);

    SDL_Delay((1000/60));
    fpsCount++;
}

