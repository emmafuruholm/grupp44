
#include <iostream>
#include <SDL.h>
#include "Session.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Enemies.hpp"


using namespace std;
using namespace game;

int main(int argc, const char * argv[]) {
    
    
    Enemies* enemies = Enemies::getInstance(3,4);
    Session ses;
    ses.add(enemies);
    
    ses.run();

    return 0;
}
