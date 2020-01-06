//
//  Element.hpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Element_hpp
#define Element_hpp
#include <SDL.h>

#include <vector>

namespace game{
    
    class Element{
        
    public:
        virtual ~Element();
        virtual void draw() const = 0;
        virtual void onFrameUpdate() = 0;
        virtual void keyDown(const SDL_Event& event){};
        virtual Element* checkCollision(std::vector<Element*>&)= 0;
        
    protected:
        Element ();
        
    private:
        Element (const Element&) = delete;
        const Element& operator= (const Element&) = delete;
        
        
    };
    
    
}

#endif /* Element_hpp */
