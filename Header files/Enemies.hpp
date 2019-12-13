//
//  Enemies.hpp
//  grupp44
//
//  Created by Tim Wahlgren on 2019-12-13.
//  Copyright © 2019 Emma Furuholm. All rights reserved.
//

#ifndef Enemies_hpp
#define Enemies_hpp
#include "Element.hpp"
#include "Enemy.hpp"
#include <vector>


namespace game {
class Enemies: public Element{
    
public:
    static Enemies* getInstance(int amount);
    ~Enemies();
    void draw() const;
    void onFrameUpdate();
    void addEnemy(int amount);
    std::vector<Enemy*> getEnemies();
    bool isEnemiesAtWindowEnd();
    bool isEnemiesAtWindowStart();
    void moveEnemiesDown();
    void moveEnemiesSideways();
    
private:
    Enemies(int amount);
    std::vector<Enemy*> enemies;
    bool isMovingToRight = true;
};
}

#endif /* Enemies_hpp */
