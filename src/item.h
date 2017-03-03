#pragma once
#include "interactable.h"

class Item:
		public interactable
{
public:
	//Constructor
	explicit Item(std::string itemImg, std::string message)
	:interactable(itemImg,message,"Item",0.6){}

	explicit Item(std::string itemImg, std::string message,std::string itemType)
		:interactable(itemImg,message,itemType){}

	explicit Item(std::string itemImg, std::string message,std::string itemType,float scale)
			:interactable(itemImg,message,itemType,scale){}

	~Item(){}

};
