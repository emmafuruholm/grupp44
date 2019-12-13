//
//  Component.hpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp
#include "Element.hpp"

#include <SDL.h>

namespace game{
    
    class Component: public Element{
        
    public:
        virtual ~Component();
        // virtual void keyDown(const SDL_Event& event){};
        // virtual void draw() const = 0;
        // virtual void onFrameUpdate() = 0;
        const SDL_Rect& getRect() const {return rect;};
        void setRectPosition(int x, int y){ rect.x = x; rect.y = y;};
        SDL_Texture* getTexture() const {return texture;};
        
    protected:
        Component (int x, int y, SDL_Surface* surf);
        Component (int x, int y, int w, int h);
        
    private:
        SDL_Rect rect;
        SDL_Texture* texture;
        Component (const Component&) = delete;
        const Component& operator= (const Component&) = delete;
        
        
    };
    
    
}

#endif /* Component_hpp */
