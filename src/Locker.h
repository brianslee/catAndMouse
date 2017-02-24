//
//  Locker.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Locker_hpp
#define Locker_hpp

#include <stdio.h>
class Locker{
public:
    void setdoorclose(); //set the status to close
    bool is_door_close(); // check if the status is closed
    
private:
    bool status; //open or closed
};

#endif /* Locker_hpp */
