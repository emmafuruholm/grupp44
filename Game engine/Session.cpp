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

#define FPS 60
#define FRAME_INTERVAL 1000 / FPS

namespace game{

void Session::add(Element* c){
    elements.push_back(c);
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
                    for(Element* e: elements){
                        e->keyDown(event);
                    }
                    
                    
            }//switch
        }//inner while
        SDL_RenderClear(sys.getRenderer());
        
        for(Element* e : elements){
            e->onFrameUpdate();
            e->draw();
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





}

