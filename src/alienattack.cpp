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
    rect.setFillColor(sf::Color::Red);
    movementSpeed = 30;
     attackDamage = 10;
     lifeTime = 10;
     direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
     destroy = false;
     counterLifetime = 0;
   
}


float projectile2::getAngle(Human& player, sf::View& view, sf::RenderWindow& window){

sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f charPos = player.getPos();
    sf::Vector2f windowPos = view.getCenter();
    charPos.x += 30;
    charPos.y += 30;
    windowPos.x -= 400;
    windowPos.y -= 400;

    /*
    sf::Vector2i p = player.getCoor();
    sf::Vector2i m = sf::Mouse::getPosition();
    
    double slope = (m.y - p.y) / (m.x - p.x);
    sf:: Vector2f d(cos(slope), sin(slope));
    */


    float angle = (-atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159) -90;
return angle;
}


void projectile2::update(Human& player, sf::View& view, sf::RenderWindow& window)
{
    
    float angle = getAngle(player, view, window);
      
    rect.move(cos((3.14159/180)*angle)* movementSpeed, sin((3.14159/180)*angle)*movementSpeed);
    
    
    
    //rect.move(0, -movementSpeed);
    
    
   // direction.x = static_cast<float>(cos(3.1415 * player.getRotation() / 180) * movementSpeed);
  //  direction.y = static_cast<float>(sin(3.1415 * player.GetRotation() / 180) * movementSpeed);
    

   /* if (direction == 1) // Up
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

    */
    
    
    counterLifetime++;
    if (counterLifetime >= lifeTime)
    {
        destroy = true;
    }


    
}
