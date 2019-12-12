
#include <iostream>
#include <SDL.h>
#include "Session.hpp"
#include "Player.hpp"


using namespace std;
using namespace game;

int main(int argc, const char * argv[]) {
    
    SDL_Surface* s = SDL_LoadBMP("/Users/perfuruholm/Hello.bmp");
    
    Player* p = Player::getInstance(0,0,s);
    SDL_FreeSurface(s);
    Session ses;
    ses.add(p);
    ses.run();

    return 0;
}
