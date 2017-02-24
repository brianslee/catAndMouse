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
	Item * i;
	bool isOpen;
public:
	explicit chest(std::string message)
	:interactable("img/square.png",message,"Chest"),isOpen(false),i(NULL){}
	
	explicit chest(std::string chestImg,std::string message)
	:interactable(chestImg,message,"Chest"),isOpen(false),i(NULL){}
	
	explicit chest(std::string chestImg, std::string message,Item * item)
	:interactable(chestImg,message,"Chest"),i(item),isOpen(false){}
	
	bool getIsOpen();

	Item * getItem();

	void setItem(Item * i);

	void open();

};


#endif /* SRC_CHEST_H_ */
