#pragma once
#include "Interactable.h"

class Item:
		public Interactable
{
public:
	explicit Item(std::string itemImg, std::string message, std::string itemName)
	:Interactable(itemImg,message,itemName){

	}
	~Item(){

	}

};
