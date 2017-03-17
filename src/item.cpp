#include "item.h"


	//Constructor
Item::Item(std::string itemImg, std::string message)
	:interactable(itemImg,message,"Item",0.6)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,float scale)
			:interactable(itemImg,message,"Item",scale)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,std::string itemType)
	:interactable(itemImg,message,itemType)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,std::string itemType,float scale)
		:interactable(itemImg,message,itemType,scale)
{
	this->setRect(0,0,32,32);
}



