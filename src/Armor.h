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
    
    //Get the hit points of the armor and returns an integer
    int get_HP();
    
    //set the hit points fo the armor and returns void
    void set_HP(int Amount); // set extra HP to players
    
private:
    int HP;
};

#endif /* Armor_hpp */
