//
//  attack.hpp
//  Attack_48
//
//  Created by James wang on 2/10/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef attack_hpp
#define attack_hpp

#include <stdio.h>
#include "entity.hpp"
class projectile: public entity
{
public:
    int movementSpeed = 10;
    int attackDamage = 1;
    int lifeTime = 300;
    
    int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
    bool destroy = false;
    int counterLifetime = 0;
    
    projectile();
    void update();
};


#endif /* attack_hpp */
