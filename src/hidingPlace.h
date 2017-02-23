#pragma once
#include "interactable.h"

class hidingPlace:
		public interactable
{
private:
	bool isOpen;
public:
	explicit hidingPlace(std::string lockerImg,std::string message)
	:interactable(lockerImg,message,"Locker"),isOpen(false){}
	
};
