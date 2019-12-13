//
//  Enemies.cpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Enemies.hpp"
#include "Enemy.hpp"
#include "System.hpp"
#include <SDL.h>

namespace game{

Enemies::Enemies(int amount){
    addEnemy(amount);
    
}

Enemies* Enemies::getInstance(int amount){
    return new Enemies(amount);
}

Enemies::~Enemies() {
    
}

void Enemies::addEnemy(int amount){
    SDL_Surface* s = SDL_LoadBMP("/Users/tim/Desktop/enemy1.bmp");
    
    for(int i = 0; i<amount; i++){
        int nextX = 0;
        if(enemies.size() > 0){
            nextX = enemies.back()->getRect().x + enemies.back()->getRect().w;
        }
        Enemy* e = Enemy::getInstance(nextX,0,s);
        enemies.push_back(e);
    }
    
}

std::vector<Enemy*> Enemies::getEnemies(){
    return enemies;
}

void Enemies::draw() const{
    for(Enemy* e : enemies){
        e->draw();
    }
}

void Enemies::onFrameUpdate(){
    // Check if enemies has reach end or start of window
    if(isEnemiesAtWindowEnd() || isEnemiesAtWindowStart()){
        isMovingToRight = !isMovingToRight; // Switch direction
        moveEnemiesDown();
    }
    moveEnemiesSideways();
}

bool Enemies::isEnemiesAtWindowEnd(){
    return isMovingToRight && enemies.back()->getRect().x + enemies.back()->getRect().w >= sys.getWindowWidht();
}

bool Enemies::isEnemiesAtWindowStart(){
    return !isMovingToRight && enemies.front()->getRect().x <= 0;
}

void Enemies::moveEnemiesSideways(){
    for(Enemy* e : enemies){
        SDL_Rect currentRect = e->getRect();
        if(isMovingToRight){
            e->setRectPosition(++currentRect.x, currentRect.y);
        } else{
            e->setRectPosition(--currentRect.x, currentRect.y);
        }
    }
}

void Enemies::moveEnemiesDown(){
    for(Enemy* e : enemies){
        SDL_Rect currentRect = e->getRect();
        e->setRectPosition(currentRect.x, currentRect.y + e->getRect().h);
    }
}

}
