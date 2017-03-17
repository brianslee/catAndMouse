//
//  Inventory.cpp
//  addfiles
//
//  Created by James wang on 2/22/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "Inventory.h"


//constructor
Inventory::Inventory(sf::Texture& texture, int h, int w){

        //split up the texture into three 
        height = h;
        width = w;
        hasItem = false;
        type="NULL";
        spriteSheet.setTexture(texture);
}

//check if the size of items in the bag, then place item after it. 
bool Inventory::addItem(std::string item){

	if(hasItem)
	{
		return false;
	}
	else
	{

		if(item == "DamageTrap"){
			hasItem = true;
			type=item;
			updateInventorySprite();
			return true;
		}else if(item=="StickyTrap"){
			hasItem=true;
			type=item;
			updateInventorySprite();
			return true;
		}
	}
}


//remove the item from inventory, update the inventory sprite
void Inventory::deleteItem()
{

        hasItem = false;
        type="NULL";
        updateInventorySprite();
}



//set the sprite of the inventory, as it is reflected in the inventory array
void Inventory::updateInventorySprite(){

        if(!hasItem)
        {
        	//change to empty sprite
			spriteSheet.setTextureRect((sf::IntRect(0, 0, height, width)));
        }
        else if(type=="DamageTrap")
        {
        	//check for bomb type and change to approprite sprite
			spriteSheet.setTextureRect((sf::IntRect(0, 1200, height, width)));

        }
        else if(type=="StickyTrap")
        {
        	spriteSheet.setTextureRect((sf::IntRect(0, 600, height, width)));
        }

}

void Inventory::setPos(float x,float y){
        spriteSheet.setPosition(x,y);
}


