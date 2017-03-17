#include "item.h"


	//Constructor
Item::Item(std::string itemImg, std::string message)
	:interactable(itemImg,message,"Item",0.6),used(false),occupied(0)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,float scale)
			:interactable(itemImg,message,"Item",scale),used(false),occupied(0)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,std::string itemType)
	:interactable(itemImg,message,itemType),used(false),occupied(0)
{
	this->setRect(0,0,32,32);
}

Item::Item(std::string itemImg, std::string message,std::string itemType,float scale)
		:interactable(itemImg,message,itemType,scale),used(false),occupied(0)
{
	this->setRect(0,0,32,32);
}

short Item::getOccupied() {
	return occupied;
}

void Item::setOccupied(short occupied) {
	this->occupied = occupied;
}

bool Item::isUsed(){
	return used;
}

void Item::setUsed(bool used) {
	this->used = used;
}


