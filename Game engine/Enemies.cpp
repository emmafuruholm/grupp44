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

void Enemies::gotShot(Component* c){
    for(std::vector<Enemy*> enemiesRow: enemies){
        
        int count = 0;
//        for(Enemy* e : enemiesRow){
            
        for(std::vector<Enemy*>::iterator i = enemiesRow.begin(); i != enemiesRow.end();)
//            if(SDL_HasIntersection(&c->getRect(), &e->getRect())){
            if(SDL_HasIntersection(&(*i)->getRect(), &c->getRect())){
//                delete *i;
//                std::cout<<"size innan borttag: "<< enemiesRow.size() <<std::endl;
                i = enemiesRow.erase(i);
//                std::cout<<"size efter borttag: "<< enemiesRow.size() <<std::endl;
//                std::cout<<"i gotshot: "<<&enemies<<std::endl;
                
//              enemies.erase(enemies.begin() + 2);
//                enemiesRow.erase(enemiesRow.begin() + 1);
                break;
                
            }else{
                i++;
            }
            count++;
        }
        
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
    
    // std::cout<<"rader:" <<enemies.size()<<std::endl;
    
//    for(std::vector<Enemy*> row : enemies){
//        std::cout<<"kolumner: "<<row.size()<<std::endl;
//    }
    
    for(std::vector<Enemy*> enemiesRow: enemies){
        for(Enemy* e : enemiesRow){
            
            e->draw();
        }
    }
    
    std::cout<<&enemies<<std::endl;
}

void Enemies::onFrameUpdate(){
    if(frameCount % 100 == 0){
        shoot();
    }
    
    if(++frameCount >= FPS / speed){
        frameCount = 0;
        // Check if enemies has reach end or start of window
        if(isEnemiesAtWindowEnd() || isEnemiesAtWindowStart()){
            isMovingToRight = !isMovingToRight; // Switch direction
            moveEnemiesDown();
            speed += 3;
        }
        moveEnemiesSideways();
    }
    
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
    enemies[enemies.size()-1][0]->shoot();
}


}
