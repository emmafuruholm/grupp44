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
#include "Component.hpp"


namespace game{
    
    class Session{
        
    public:
        void add(Component* c);
        void remove(Component* c);
        void run();
        ~Session();
        
    private:
        std::vector<Component*> components;
        std::vector<Component*> removed, added;
        void handleKeyDown(SDL_Event& event);
        void setDelay(Uint32 nextFrame);
    
    };
extern Session session;
    
}


#endif /* Session_hpp */
