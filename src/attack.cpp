//
//  attack.cpp
//  Attack_48
//
//  Created by James wang on 2/10/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "attack.h"

projectile::projectile()
{
    rect.setSize(sf::Vector2f(10, 10));
    rect.setFillColor(sf::Color::Green);
     movementSpeed = 10;
     attackDamage = 1;
     lifeTime = 300;
    
     direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
     destroy = false;
     counterLifetime = 0;
}


void projectile::updateProjectile(Character& player, sf::View& view, sf::RenderWindow& window)
{
    //sf::Vector2f loc(sf::Mouse::getPosition());
   //rect.move(direction.x,direction.y);
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f charPos = player.getPos();
    sf::Vector2f windowPos = view.getCenter();
    charPos.x += 30;
    charPos.y += 30;
    windowPos.x -= 400;
    windowPos.y -= 400;
    
    float angle = (-atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159) -90;
    
    rect.move(cos((3.14159/180)*angle)* movementSpeed, sin((3.14159/180)*angle)*movementSpeed);
    
    
    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }
    
}
