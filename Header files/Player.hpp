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
#include "Pistol.hpp"

#include <vector>

namespace game {

class Player : public Component {

    public:
        static Player* getInstance(int x, int y, SDL_Surface* surf);
        ~Player();
        void keyDown(const SDL_Event& event);
        void draw() const;
        void onFrameUpdate();
        Component* checkCollision(std::vector<Component*>&);
    bool gotShot(Component*);

    private:
        Player(int x, int y, SDL_Surface* surf);
        Pistol* pistol = Pistol::getInstance();

    };

}

#endif /* Player_hpp */
