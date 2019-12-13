//
//  System.hpp
//  grupp44
//
//  Created by Erik Åkerberg on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef System_hpp
#define System_hpp

#include <SDL.h>
// #include <SDL_ttf.h>

namespace game {
    
    class System{
        
    public:
        System();
        ~System();
        SDL_Renderer* getRenderer() const;
        int getWindowWidht();
        // TTF_Font* getFont() const;
        
        
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        
    };
    
    extern System sys;
    
}

#endif /* System_hpp */
