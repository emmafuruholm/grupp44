//
//  enemy.cpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Enemy.hpp"
#include "System.hpp"
#include "Session.hpp"

#include <vector>
#include <iostream>

namespace game{

Enemy::Enemy(int x, int y, SDL_Surface* surf): Component(x, y, surf){
    
}

Enemy* Enemy::getInstance(int x, int y, SDL_Surface *surf){
    return new Enemy(x, y, surf);
}

Enemy::~Enemy() {
    std::cout<<"enemy got erased"<<std::endl;
}

bool Enemy::gotShot(Component*){
    return true;
}

Component* Enemy::checkCollision(std::vector<Component*>& components){
    return NULL;
}

void Enemy::draw() const{
    SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
}

void Enemy::shoot(){
    pistol->shoot(rect.x + rect.w /2, rect.y + rect.h, false);
}

}
