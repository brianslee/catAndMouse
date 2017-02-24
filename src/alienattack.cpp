//
//  alienattack.cpp
//  Attack_48
//
//  Created by James wang on 2/12/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "alienattack.h"

projectile2::projectile2()
{
    rect.setSize(sf::Vector2f(6, 6));
    rect.setFillColor(sf::Color::Black);
    movementSpeed = 10;
     attackDamage = 10;
     lifeTime = 50;
     direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
     destroy = false;
     counterLifetime = 0;
   
}

void projectile2::update()
{
    if (direction == 1) // Up
    {
        rect.move(0, -movementSpeed);
    }
    if (direction == 2) // Down
    {
        rect.move(0, movementSpeed);
    }
    if (direction == 3) // Left
    {
        rect.move(-movementSpeed, 0);
    }
    if (direction == 4) // Right
    {
        rect.move(movementSpeed, 0);
    }
    
    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }
    
}
