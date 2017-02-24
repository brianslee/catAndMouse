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
    projectile2();//constructor 
    void update(); // update the movement and exist time of the projectile
private:
    int movementSpeed; 
    int attackDamage;
    float lifeTime; //preset the existing time of a projectile
    int direction; // 1 - up, 2 - down, 3 - left, 4 - right
    bool destroy; 
    int counterLifetime;// counting the existing time 
};

#endif /* alienattack_h */
