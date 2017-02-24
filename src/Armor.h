//
//  Armor.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Armor_hpp
#define Armor_hpp

#include <stdio.h>
class armor{
public:
    int get_HP();
    void set_HP(int Amount); // set extra HP to players
    
private:
    int HP;
};

#endif /* Armor_hpp */
