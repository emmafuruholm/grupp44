//
//  Pistol.hpp
//  grupp44
//
//  Created by Tim Wahlgren on 2020-01-06.
//  Copyright © 2020 Emma Furuholm. All rights reserved.
//

#ifndef Pistol_hpp
#define Pistol_hpp

#include <stdio.h>
#include "Session.hpp"

namespace game {
class Pistol{
public:
    static Pistol* getInstance();
    ~Pistol();
    void shoot(int x, int y, bool initialDirUpwards);
    
private:
    Pistol();
    
};
}

#endif /* Pistol_hpp */
