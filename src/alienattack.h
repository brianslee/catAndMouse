//
//  alienattack.h
//  Attack_48
//
//  Created by James wang on 2/12/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef alienattack_h
#define alienattack_h

#include <stdio.h>

#include "entity.h"
class projectile2: public entity
{
public:
    int movementSpeed = 10;
    int attackDamage = 10;
    float lifeTime = 50;
    int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
    bool destroy = false;
    int counterLifetime = 0;
    
    projectile2();
    void update();
};

#endif /* alienattack_h */