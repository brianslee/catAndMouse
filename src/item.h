#pragma once
#include "interactable.h"

class Item:
		public interactable
{
private:
	bool used;
	bool occupied;
public:
	//Constructor
	explicit Item(std::string itemImg, std::string message);

	explicit Item(std::string itemImg, std::string message,float scale);

	explicit Item(std::string itemImg, std::string message,std::string itemType);

	explicit Item(std::string itemImg, std::string message,std::string itemType,float scale);

	bool getOccupied();

	void setOccupied(bool occupied);

	bool isUsed() ;

	void setUsed(bool used) ;
};
