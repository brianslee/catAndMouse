#pragma once
#include "interactable.h"

class Item:
		public interactable
{
private:
	bool used;
	short occupied; //0= on map, 1= marine, 2=aliean
public:
	//Constructor
	explicit Item(std::string itemImg, std::string message);

	explicit Item(std::string itemImg, std::string message,float scale);

	explicit Item(std::string itemImg, std::string message,std::string itemType);

	explicit Item(std::string itemImg, std::string message,std::string itemType,float scale);

	short getOccupied();

	void setOccupied(short occupied);

	bool isUsed() ;

	void setUsed(bool used) ;
};
