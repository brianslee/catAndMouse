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
    bool addItem(std::string item); // add a item
    void deleteItem(std::string item); //delete a item
    Inventory(sf::Texture& texture, int h, int w);
    void updateInventorySprite();
    void setPos(float x, float y);
    sf::Sprite& getSprite() {return spriteSheet;}
   // bool isFull() {return hasItem;}   
private:
   // std::string *Items_in_bag[]; // items list
    bool hasItem;
    int height;
    int width;

    sf::Sprite spriteSheet;
};

#endif /* Inventory_hpp */
