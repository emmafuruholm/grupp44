//
//  Component.cpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//




#include "Component.hpp"
#include "System.hpp"
#include <SDL.h>

namespace game{

Component::Component(int x, int y, SDL_Surface* surf):rect{x, y, surf->w, surf->h}{
    texture = SDL_CreateTextureFromSurface(sys.getRenderer(), surf);
    
    // TODO - free surface här eller där man skapar objektet?
    
}

Component::Component(int x, int y, int w, int h):rect{x, y, w, h}{}



Component::~Component(){
    SDL_DestroyTexture(texture);
}

}



