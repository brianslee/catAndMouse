//
//  alienattack.cpp
//  Attack_48
//
//  Created by James wang on 2/12/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "alienattack.hpp"

projectile2::projectile2()
{
    rect.setSize(sf::Vector2f(6, 6));
    //rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Black);
   
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
