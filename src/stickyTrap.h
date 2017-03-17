//
//  stickyTrap.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef stickyTrap_hpp
#define stickyTrap_hpp

#include <stdio.h>
class stickyTrap{
    
public:
    void set_movement_speed(int speed); // set a new movement speed to the player
    int get_speed();
    
private:
    int Speed;

};

#endif /* stickyTrap_hpp */
