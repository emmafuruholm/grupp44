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
#include <vector>

namespace game{
    
    class Component{
        
    public:
        virtual ~Component();
       
        virtual void draw() const = 0;
        virtual void onFrameUpdate() = 0;
        virtual void keyDown(const SDL_Event& event){};
        virtual Component* checkCollision(std::vector<Component*>&)=0;
        const SDL_Rect& getRect() const {return rect;};
        void setRectPosition(int x, int y){ rect.x = x; rect.y = y;};
        SDL_Texture* getTexture() const {return texture;};
        virtual void gotShot(Component*) = 0;
        
    protected:
        Component (int x, int y, SDL_Surface* surf);
        Component (int x, int y, int w, int h);
        Component(){};
        SDL_Rect rect;

        
    private:
        SDL_Texture* texture;
        Component (const Component&) = delete;
        const Component& operator= (const Component&) = delete;
        
        
    };
    
    
}

#endif /* Component_hpp */
