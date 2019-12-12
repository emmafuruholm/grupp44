//
//  Component.hpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include <SDL.h>

namespace game{
    
    class Component{
        
    public:
        virtual ~Component();
        virtual void keyDown(const SDL_Event& event){};
        virtual void draw() const = 0;
        virtual void onFrameUpdate() = 0;
        const SDL_Rect& get_rect() const {return rect;};
        
    protected:
        Component (int x, int y, int w, int h);
        
    private:
        SDL_Rect rect;
        Component (const Component&) = delete;
        const Component& operator= (const Component&) = delete;
        
        
    };
    
    
}

#endif /* Component_hpp */
