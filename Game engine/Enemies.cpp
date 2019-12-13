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


Enemies::Enemies(int rows, int columns){
    SDL_Surface* s = SDL_LoadBMP("/Users/tim/Desktop/enemy1.bmp");
    
    for (int row = 0; row < rows; row++) {
        std::vector<Enemy*> currentColumn;
        int nextY = s->h * row;
        
        for (int column = 0; column < columns; column++) {
            int nextX = s->w * column;
            Enemy* e = Enemy::getInstance(nextX,nextY,s);
            currentColumn.push_back(e);
        }
        
        enemies.push_back(currentColumn);
        
    }
}

Enemies* Enemies::getInstance(int rows, int columns){
    return new Enemies(rows, columns);
}


Enemies::~Enemies() {
    
}

std::vector<std::vector<Enemy*>> Enemies::getEnemies(){
    return enemies;
}

void Enemies::removeEnemy(int row, int column){
    Enemy* temp = enemies[row][column];
    enemies[row].erase(enemies[row].begin() + column);
    delete temp;
}

void Enemies::draw() const{
    for(std::vector<Enemy*> enemiesColumn: enemies){
        for(Enemy* e : enemiesColumn){
            e->draw();
        }
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
    for(std::vector<Enemy*> enemiesRow: enemies){
        Enemy* lastEnemy = enemiesRow.back();
        if(isMovingToRight && lastEnemy->getRect().x + lastEnemy->getRect().w >= sys.getWindowWidht()){
            return true;
        }
    }
    return false;
    
    // return isMovingToRight && enemies.back()->getRect().x + enemies.back()->getRect().w >= sys.getWindowWidht();
}

bool Enemies::isEnemiesAtWindowStart(){
    for(std::vector<Enemy*> enemiesRow: enemies){
        Enemy* firstEnemy = enemiesRow.front();
        if(! isMovingToRight && firstEnemy->getRect().x <= 0){
            return true;
        }
    }
    return false;
    // return !isMovingToRight && enemies.front()->getRect().x <= 0;
}

void Enemies::moveEnemiesSideways(){
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            SDL_Rect currentRect = e->getRect();
            if(isMovingToRight){
                e->setRectPosition(++currentRect.x, currentRect.y);
            } else{
                e->setRectPosition(--currentRect.x, currentRect.y);
            }
        }
    }
}

void Enemies::moveEnemiesDown(){
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            SDL_Rect currentRect = e->getRect();
            e->setRectPosition(currentRect.x, currentRect.y + e->getRect().h);
        }
    }
}

}
