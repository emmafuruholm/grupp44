//
//  Pistol.cpp
//  grupp44
//
//  Created by Tim Wahlgren on 2020-01-06.
//  Copyright © 2020 Emma Furuholm. All rights reserved.
//

#include "Pistol.hpp"
#include "Bullet.hpp"

#include "Session.hpp"

#include <SDL.h>

#include <iostream>

namespace game{

Pistol* Pistol::getInstance(){
    return new Pistol();
}

Pistol::Pistol(){
    
}

Pistol::~Pistol(){
    
}

void Pistol::shoot(int x, int y, bool initialDirUpwards){
    
    SDL_Surface* bulletSurf = SDL_LoadBMP("/Users/tim/Desktop/arrow_top.bmp");
    
    int bulletSurfHeight = bulletSurf->h;

    int yOffset = initialDirUpwards ? -bulletSurfHeight : bulletSurfHeight;
    
    Bullet* b = Bullet::getInstance(x, y+yOffset, bulletSurf, true );
    
    
    
    session.add(b);
    
    
    
    
}


}
