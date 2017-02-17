#pragma once
#include "Interactable.h"

class HidingPlace:
		public Interactable
{
private:
	bool isOpen;
public:
	explicit HidingPlace(std::string lockerImg,std::string message)
	:Interactable(lockerImg,message,"Locker")
	{
		isOpen=false;
	}
};
