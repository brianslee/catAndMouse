//
//  Inventory.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//
//  Modified by Zeyu Zhu on 2017-3-9

#ifndef Inventory_hpp
#define Inventory_hpp
#include "item.h"
#include <stdio.h>
#include <string>
class Inventory{
public:
    void add_item(std::string new_item); // add a item
    void delete_item(std::string used_item); //delete a item

    
private:
	
};

#endif /* Inventory_hpp */
