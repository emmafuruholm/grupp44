//
//  Session.cpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Session.hpp"
#include <SDL.h>
#include "Element.hpp"
#include "System.hpp"

using namespace std;

namespace game{

void Session::add(Component* c){
    components.push_back(c);
}

void Session::remove(Component* c){
    removed.push_back(c);
}

void Session::run(){
    
    bool quit = false;
    
    while(!quit){
        Uint32 nextFrame = SDL_GetTicks() + FRAME_INTERVAL;
        SDL_Event event;
        
        while(SDL_PollEvent(&event)){
            
            switch(event.type){
                    
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    for(Component* c : components){
                        c->keyDown(event);
                    }
                    
                    
            }//switch
        }//inner while
        
        for(Component* c : components){
            c->onFrameUpdate();
        }
        
        //checkCollision
        for(Component* c : components){
            Component* collidedWith = c->checkCollision(components);
            
            if(collidedWith != NULL){
//                c->gotHit(collidedWith);
//                collidedWith->gotHit(c);
                break;
            }
        }
        
        //addNewComponents
        for(Component* e:added){
            components.push_back(e);
        }
        added.clear();
        
        
        //removeComponents
        for(Component* c:removed){
            for(vector<Component*>::iterator i = components.begin(); i!=components.end();)
                if(*i==c){
                    i=components.erase(i);
                    //e->~Element();
                    delete c;
                }else{
                    i++;
                }
        }
        removed.clear();
        
        
        
        
        SDL_RenderClear(sys.getRenderer());
        
        for(Component* c : components){
            
            c->draw();
        }
        
        SDL_RenderPresent(sys.getRenderer());
        
        setDelay(nextFrame); // Set delay for next frame update
        
        
    }//outer while
}//run()

void Session::setDelay(Uint32 nextFrame){
    int delay = nextFrame - SDL_GetTicks();
    if(delay > 0){
        SDL_Delay(delay);
    }
}

Session::~Session(){
    
}

Session session;



}

