//
//  Door.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Door_hpp
#define Door_hpp

#include <stdio.h>
class Door{
public:
    void open(); //set the status to open
    void close();  //set the status to close
    bool is_open();  //check the status if it is open, returns boolean
    bool is_closed();  //check the status if it is closed, returns boolean 
    
private:
    bool status; //close or open
    
};

#endif /* Door_hpp */
