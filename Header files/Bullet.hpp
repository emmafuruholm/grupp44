//
//  Bullet.hpp
//  grupp44
//
//  Created by Tim Wahlgren on 2020-01-06.
//  Copyright © 2020 Emma Furuholm. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>

#include "Component.hpp"

#include <SDL.h>
#include <vector>


namespace game{
    
    class Bullet : public Component{
        
    public:
        static Bullet* getInstance(int x, int y, SDL_Surface* bulletSurf, bool initialDirUpwards);
        void draw() const;
        void onFrameUpdate();
        ~Bullet();
//        void checkCollision(Session*);
        Component* checkCollision(std::vector<Component*>&);
        void gotHit(Component* other){};
        void gotShot(Component*);
        
        
    private:
        Bullet(int x, int y, SDL_Surface* bulletSurf, bool initialDirUpwards);
        bool initialDirUpwards;
        static int bulletIdCount;
//        SDL_Surface* bulletSurf; Kan inte denna initieras här??
        
    };
    
    
    
}


#endif /* Bullet_hpp */
