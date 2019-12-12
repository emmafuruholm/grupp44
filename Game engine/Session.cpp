//
//  Session.cpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#include "Session.hpp"
#include <SDL.h>
#include "Component.hpp"
#include "System.hpp"

namespace game{
    
    void Session::add(Component* c){
        components.push_back(c);
    }
    
    void Session::run(){
        
        
        bool quit = false;
        
        while(!quit){
            SDL_Event event;
            
            while(SDL_PollEvent(&event)){
                
                switch(event.type){
                        
                    case SDL_QUIT:
                        quit = true;
                        break;
                    case SDL_KEYDOWN:
                        for(Component* c: components){
                            c->keyDown(event);
                        }
                        
                        
                }//switch
            }//inner while
            SDL_RenderClear(sys.getRenderer());
            
            for(Component* c : components){
                c->draw();
            }
            
            SDL_RenderPresent(sys.getRenderer());
            
        }//outer while
        
        
        
    }//run()
    
    Session::~Session(){
        
    }
    
    
    
    
    
}

