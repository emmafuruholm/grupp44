//
//  Session.hpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Session_hpp
#define Session_hpp


#include <vector>
#include <SDL.h>
#include "Element.hpp"


namespace game{
    
    class Session{
        
    public:
        void add(Element* c);
        void run();
        ~Session();
        
    private:
        std::vector<Element*> elements;
        void handleKeyDown(SDL_Event& event);
        void setDelay(Uint32 nextFrame);
    
    };
    
    
}


#endif /* Session_hpp */
