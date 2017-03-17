#pragma once
#include "interactable.h"

class hidingPlace:
		public interactable
{
protected:
	int visibility;
	bool isOccupied;
public:
//	explicit hidingPlace(std::string img,std::string message,float scale,int visibility);

	explicit hidingPlace(std::string img,std::string message,std::string type,float scale,int visibility);

	int getVisibility();

	bool getIsOccupied();

	void setIsOccupied(bool io);




	
};
