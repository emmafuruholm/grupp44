//
//  Player.cpp
//  grupp44
//
//  Created by Emma Furuholm on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Player.hpp"
#include "System.hpp"
#include <SDL.h>

namespace game {

    Player::Player(int x, int y, SDL_Surface* surf):Component(x, y, surf) {
        
    }

    Player* Player::getInstance(int x, int y, SDL_Surface* surf) {
        return new Player(x, y, surf);
    }


    Player::~Player() {
    
    }
    
    void Player::keyDown(const SDL_Event& event){
        
    }
    void Player::draw() const {
        SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
    
    }
    void Player::onFrameUpdate(){
    
    }


}
