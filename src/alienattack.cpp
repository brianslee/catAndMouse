//
//  alienattack.cpp
//  Attack_48
//
//  Created by James wang on 2/12/17.
//  Copyright 2017 James wang. All rights reserved.
//

#include "alienattack.h"

projectile2::projectile2()
{
    rect.setSize(sf::Vector2f(6, 6));
    rect.setFillColor(sf::Color::Red);
    movementSpeed = 9;
     attackDamage = 10;
     lifeTime = 50;
     direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
     destroy = false;
     counterLifetime = 0;
     angle=0;
   
}


float projectile2::getPlayerAngle(Character* player, sf::View& view, sf::RenderWindow& window){
	angle=player->getAngle(view,window);
	return angle;
}


void projectile2::updateProjectile2()
{
    rect.move(cos((3.14159/180)*angle)* movementSpeed, sin((3.14159/180)*angle)*movementSpeed);

    counterLifetime++;
    if (counterLifetime >= lifeTime)
    	destroy = true;

}
