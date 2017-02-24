//
//  weapon.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include <SFML/Graphics.hpp>

#ifndef weapon_hpp
#define weapon_hpp

#include <stdio.h>
class Weapon{
public:
    void setSprite(); //set the sprite of the weapon
    void setDamage();//set the damage of the weapon
    void setAttackRange(); //set the attackrange
    
private:
    int damage;
    int attackRange;
    sf::Sprite Sprite;
    
};

#endif /* weapon_hpp */
