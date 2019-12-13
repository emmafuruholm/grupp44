//
//  System.cpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "System.hpp"
#include <iostream>
#include <SDL.h>
// #include <stdexcept>

using namespace std;

namespace game {

System::System(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Error in class system" << SDL_GetError()<< endl;
    }
    
    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
    
    if(window == NULL){
        std::cout << "could not initialize window: "<< SDL_GetError()<<std::endl;
    }
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(renderer == NULL){
        std::cout << "could not initialize renderer: "<< SDL_GetError()<<std::endl;
    }
}

System::~System(){
    // Close font
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* System::getRenderer() const {
    return renderer;
}

int System::getWindowWidht() {
    int i;
    int* p = {&i};
    SDL_GetWindowSize(window,p,NULL);
    return i;
}

System sys;

}
