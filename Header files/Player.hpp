//
//  Player.hpp
//  grupp44
//
//  Created by Emma Furuholm on 2019-12-12.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Component.hpp"

namespace game {

class Player : public Component {

    public:
        static Player* getInstance(int x, int y, SDL_Surface* surf);
        ~Player();
        void keyDown(const SDL_Event& event);
        void draw() const;
        void onFrameUpdate();
    

    private:
        Player(int x, int y, SDL_Surface* surf);

    };

}

#endif /* Player_hpp */
