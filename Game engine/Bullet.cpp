//
//  Bullet.cpp
//  grupp44
//
//  Created by Tim Wahlgren on 2020-01-06.
//  Copyright © 2020 Emma Furuholm. All rights reserved.
//

#include "Bullet.hpp"
#include "System.hpp"
#include "Session.hpp"
#include "Component.hpp"

#include <SDL.h>
#include <iostream>
#include <vector>

using namespace std;

namespace game{
    
    
    
    Bullet::Bullet(int x, int y, SDL_Surface* bulletSurf, bool dir):Component(x,y,bulletSurf), initialDirUpwards(dir){
    }
    
    Bullet* Bullet::getInstance(int x, int y, SDL_Surface* bulletSurf, bool initialDirUpwards){
        return new Bullet(x,y, bulletSurf, initialDirUpwards);
    }
    
    Bullet::~Bullet(){}
    
    
    void Bullet::draw() const {
        SDL_RenderCopy(sys.getRenderer(), getTexture(), NULL, &getRect());
    }
    

    
    
   Component* Bullet::checkCollision(vector<Component*>& components){

        for(Component* c : components){
            if( c != this && SDL_HasIntersection(&rect, &c->getRect())){
//                cout<<"Träff mellan " +c->getIdTag() +" och "+ idTag<<endl;
                cout<<"träff"<<endl;
                return c;
            }
        }
        return NULL;
    }
    
    int Bullet::bulletIdCount = 0;
    
    void Bullet::onFrameUpdate(){
        

        
        if(rect.y<=0 || rect.y>=sys.getWindowHeight()){
            session.remove(this);

        }

        
        else{
            rect.y--;
        }
    }
    
   
}
