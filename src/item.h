#pragma once
#include "interactable.h"

class Item:
		public interactable
{
public:
	//Constructor
	explicit Item(std::string itemImg, std::string message)
	:interactable(itemImg,message,"Item"){}

	explicit Item(std::string itemImg, std::string message,std::string itemType)
		:interactable(itemImg,message,itemType){}

	~Item(){}

};
