#pragma once
#include "interactable.h"

class Item:
		public interactable
{
public:
	//Constructor
	explicit Item(std::string itemImg, std::string message);

	explicit Item(std::string itemImg, std::string message,float scale);

	explicit Item(std::string itemImg, std::string message,std::string itemType);

	explicit Item(std::string itemImg, std::string message,std::string itemType,float scale);


	~Item(){}

};
