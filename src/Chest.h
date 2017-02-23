#pragma once
#ifndef SRC_CHEST_H_
#define SRC_CHEST_H_

#pragma once
#include "Interactable.h"
#include "Item.h"


class Chest:
		public Interactable
{
private:
	Item * i;
	bool isOpen;
public:
	explicit Chest(std::string message)
	:Interactable("img/square.png",message,"Chest"),isOpen(false),i(NULL){}
	
	explicit Chest(std::string chestImg,std::string message)
	:Interactable(chestImg,message,"Chest"),isOpen(false),i(NULL){}
	
	explicit Chest(std::string chestImg, std::string message,Item * item)
	:Interactable(chestImg,message,"Chest"),i(item),isOpen(false){}
	
	bool getIsOpen();

	Item * getItem();

	void setItem(Item * i);

	void open();

};


#endif /* SRC_CHEST_H_ */
