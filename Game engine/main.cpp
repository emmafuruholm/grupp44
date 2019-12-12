
#include <iostream>
#include <SDL.h>
#include "Session.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    game::Session ses;
    ses.run();

    return 0;
}
