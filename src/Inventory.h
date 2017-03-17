//
//  Inventory.hpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp




#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>
class Inventory{
public:
    
    //Add item to the inventory
    bool addItem(std::string item);
    
    //Delete an item from the inventory
    void deleteItem(std::string item);

    //Constructor that sets the inventory sprite
    Inventory(sf::Texture& texture, int h, int w);
    
    //Changes the state of the sprite  
    void updateInventorySprite();
    
    //Change the position of the inventory
    void setPos(float x, float y);
    
    //Returns the sprite of the inventory
    sf::Sprite& getSprite() {return spriteSheet;}
    
private:
   // std::string *Items_in_bag[]; // items list
    bool hasItem;
    int height;
    int width;

    sf::Sprite spriteSheet;
};

#endif /* Inventory_hpp */
