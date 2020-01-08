//
//  Player.cpp
//  grupp44
//
//  Created by Emma Furuholm on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Player.hpp"
#include "System.hpp"
#include "Pistol.hpp"
#include <SDL.h>

#include <vector>
#include <iostream>

using namespace std;


namespace game {

Player::Player(int x, int y, SDL_Surface* surf):Component(x, y, surf) {
    
}

Player* Player::getInstance(int x, int y, SDL_Surface* surf) {
    return new Player(x, y, surf);
}


Player::~Player() {
    
}

Component* Player::checkCollision(vector<Component*>& components){
    return NULL;
}


void Player::keyDown(const SDL_Event& event){
    switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            if(rect.x >= 0){
                rect.x -=5;
            } else{
                rect.x = 0;
            }
            break;
        case SDLK_RIGHT:
            
            if(rect.x +rect.w <= sys.getWindowWidht()){
                rect.x+=5;
            }
            else{
                rect.x = sys.getWindowWidht()-rect.w;
            }
            break;
        case SDLK_SPACE:
            
            pistol->shoot(rect.x, rect.y, true);
            break;
            
        
    }
}

void Player::gotShot(Component*){
    std::cout<<"spelare skjuten"<<std::endl;
}

void Player::draw() const {
    SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
    
}
void Player::onFrameUpdate(){
    
}


}
