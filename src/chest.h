#pragma once
#ifndef SRC_CHEST_H_
#define SRC_CHEST_H_

#pragma once
#include "interactable.h"
#include "item.h"


class chest:
		public interactable
{
private:
	Item * i; //The item in the chest, it could be null
	bool isOpen; //if the chest open or not
public:
	//constructor
	explicit chest(std::string message)
	:interactable("img/square.png",message,"Chest"),isOpen(false),i(NULL){}
	
	explicit chest(std::string chestImg,std::string message)
	:interactable(chestImg,message,"Chest"),isOpen(false),i(NULL){}
	
	explicit chest(std::string chestImg, std::string message,Item * item)
	:interactable(chestImg,message,"Chest"),i(item),isOpen(false){}
	
	bool getIsOpen(); //return if the chest is open

	Item * getItem(); //return the item in the chest

	void setItem(Item * i); //set the item "inside" the chest

	void open(); // Open the chest

};


#endif /* SRC_CHEST_H_ */
