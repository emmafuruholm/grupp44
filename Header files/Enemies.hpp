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
class Enemies: public Component{
    
public:
    static Enemies* getInstance(int rows, int columns);
    ~Enemies();
    void draw() const;
    void onFrameUpdate();
    void removeEnemy(int row, int column);
    Component* checkCollision(std::vector<Component*>&);
    bool gotShot(Component*);
    
private:
    Enemies(int rows, int columns);
    std::vector<std::vector<Enemy*>> enemies;
    bool isMovingToRight = true;
    int frameCount = 0;
    int speed = 3; // Higher number is higher speed. 1 == 1 move per second.
    void shoot();
    bool willShoot();
    bool isEnemiesAtWindowEnd();
    bool isEnemiesAtWindowStart();
    void moveEnemiesDown();
    void moveEnemiesSideways();
    void checkWin();
    int getFronRow();
    
};
}

#endif /* Enemies_hpp */
