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

#include <iostream>

namespace game{


Enemies::Enemies(int rows, int columns){
    SDL_Surface* s = SDL_LoadBMP("../../../../../../../../xCode/grupp44/images/enemy.bmp");
    
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
    
    int width = s->w * columns;
    int height = s->h * rows;
    rect = {0, 0, width, height};
    
}

Enemies* Enemies::getInstance(int rows, int columns){
    return new Enemies(rows, columns);
}


Enemies::~Enemies() {
    
}

Component* Enemies::checkCollision(std::vector<Component*>& components){
    //    for(std::vector<Enemy*> enemiesColumn: enemies){
    //        for(Enemy* e : enemiesColumn){
    //            Component* collidedWith = e->checkCollision(components);
    //            if(collidedWith != NULL){
    //               std:: cout<<"träff"<<std::endl;
    //                return collidedWith;
    //            }
    //        }
    //    }
    return NULL;
};

bool Enemies::gotShot(Component* c){
    for(int i = 0; i < enemies.size(); i++){
        for(int j = 0; j< enemies[i].size(); j++){
            if(SDL_HasIntersection(&enemies[i][j]->getRect(), &c->getRect())){
                delete enemies[i][j];
                enemies[i].erase(enemies[i].begin() + j);
                return true;
            }
        }
    }
    checkWin();
    return false;
}




void Enemies::removeEnemy(int row, int column){
    Enemy* temp = enemies[row][column];
    enemies[row].erase(enemies[row].begin() + column);
    delete temp;
    
}

void Enemies::draw() const{
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            e->draw();
        }
    }
}

void Enemies::onFrameUpdate(){
    
    if(++frameCount >= FPS / speed){
        frameCount = 0;
        // Check if enemies has reach end or start of window
        if(isEnemiesAtWindowEnd() || isEnemiesAtWindowStart()){
            isMovingToRight = !isMovingToRight; // Switch direction
            moveEnemiesDown();
            speed += 3;
        }
        moveEnemiesSideways();
        if(willShoot()){
            shoot();
        }
    }
    
}

bool Enemies::isEnemiesAtWindowEnd(){ for(std::vector<Enemy*> enemiesRow: enemies){
        if(enemiesRow.size() > 0){
            Enemy* lastEnemy = enemiesRow.back();
            if(isMovingToRight && lastEnemy->getRect().x + lastEnemy->getRect().w >= sys.getWindowWidht()){
                return true;
            }
        }
    }
    return false;
    
    // return isMovingToRight && enemies.back()->getRect().x + enemies.back()->getRect().w >= sys.getWindowWidht();
}

bool Enemies::isEnemiesAtWindowStart(){
    for(std::vector<Enemy*> enemiesRow: enemies){
        if(enemiesRow.size() > 0){
            Enemy* firstEnemy = enemiesRow.front();
            if(! isMovingToRight && firstEnemy->getRect().x <= 0){
                return true;
            }
        }
    }
    return false;
    // return !isMovingToRight && enemies.front()->getRect().x <= 0;
}

void Enemies::moveEnemiesSideways(){
    // Moving each enemy
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            SDL_Rect currentRect = e->getRect();
            if(isMovingToRight){
                e->setRectPosition(currentRect.x += 5, currentRect.y);
            } else{
                e->setRectPosition(currentRect.x -= 5, currentRect.y);
            }
        }
    }
    // Moving this
    if(isMovingToRight){
        rect.x += 5;
    } else{
        rect.x -= 5;
    }
}

void Enemies::moveEnemiesDown(){
    // Moving each enemy
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            SDL_Rect currentRect = e->getRect();
            e->setRectPosition(currentRect.x, currentRect.y + e->getRect().h / 2);
        }
    }
    //Moving this
    rect.y = rect.y + enemies[0][0]->getRect().h / 2;
}

void Enemies::shoot(){
    int frontRow = getFronRow();
    int randIndex = rand() % enemies[frontRow].size();
    enemies[frontRow][randIndex]->shoot();
}

bool Enemies::willShoot(){
    return rand() % (3*speed) == 0;
}

void Enemies::checkWin(){
    bool hasWon = true;
    for(std::vector<Enemy*> enemiesRow: enemies){
        hasWon = enemiesRow.size() == 0;
    }
    if(hasWon){
        // session.onWinning() typ
    }
}

int Enemies::getFronRow(){
    int frontRow = 0;
    for(int i = 0; i < enemies.size(); i++){
        if(enemies[i].size() > 0){
            frontRow = i;
        }
    }
    return frontRow;
}


}
