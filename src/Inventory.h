//
//  Inventory.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <string>
class Inventory{
public:
    void add_item(std::string new_item); // add a item
    void delete_item(std::string used_item); //delete a item

    
private:
    std::string *Items_in_bag[]; // items list
};

#endif /* Inventory_hpp */
