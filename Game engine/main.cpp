
#include <iostream>
#include <SDL.h>
#include "Session.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Enemies.hpp"

#include "System.hpp"
#include "Bullet.hpp"


using namespace std;
using namespace game;

int main(int argc, const char * argv[]) {
    
    
    Enemies* enemies = Enemies::getInstance(3,4);
   
    
    SDL_Surface* surf=SDL_LoadBMP("/Users/tim/Desktop/player1.bmp");
    Player* p = Player::getInstance(0, sys.getWindowHeight()-(surf->h), surf);
//    SDL_Surface* bSurf = SDL_LoadBMP("/Users/tim/Desktop/arrow_top.bmp");
//    Bullet* b = Bullet::getInstance(5,250, bSurf, true);
//    ses.add(b);
    session.add(p);
    session.add(enemies);
    
    session.run();

    return 0;
}
