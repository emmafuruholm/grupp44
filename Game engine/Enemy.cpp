//
//  enemy.cpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Enemy.hpp"
#include "System.hpp"

namespace game{

Enemy::Enemy(int x, int y, SDL_Surface* surf): Component(x, y, surf){
    
}

Enemy* Enemy::getInstance(int x, int y, SDL_Surface *surf){
    return new Enemy(x, y, surf);
}

Enemy::~Enemy() {

}

void Enemy::draw() const{
    SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
}

}
