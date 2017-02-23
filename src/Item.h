#pragma once
#include "Interactable.h"

class Item:
		public Interactable
{
public:
	explicit Item(std::string itemImg, std::string message)
	:Interactable(itemImg,message,"Item"){}

	explicit Item(std::string itemImg, std::string message,std::string itemType)
		:Interactable(itemImg,message,itemType){}

	~Item(){}

};
