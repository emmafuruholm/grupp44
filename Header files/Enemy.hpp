//
//  enemy.hpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Enemy_hpp
#define Enemy_hpp
#include "Component.hpp"
#include <vector>
#include "Pistol.hpp"

namespace game {
class Enemy : public Component{
    
public:
    static Enemy* getInstance(int x, int y, SDL_Surface* surf);
    ~Enemy();
    void keyDown(const SDL_Event& event){};
    void draw() const;
    void onFrameUpdate(){};
    Component* checkCollision(std::vector<Component*>&);
    void gotShot(Component*);
    void shoot();
    
private:
    Enemy(int x, int y, SDL_Surface* surf);
    Pistol* pistol = Pistol::getInstance();
    
};
}

#endif /* Enemy_hpp */
