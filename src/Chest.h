#pragma once
#include "Interactable.h"
#include "Item.h"


class Chest:
		public Interactable
{
private:
	Item * i;
	bool isOpen;
public:
	explicit Chest(std::string message)
	:Interactable("img/square.png",message,"Chest")
	{
		isOpen=false;
		i=NULL;
	}
	explicit Chest(std::string chestImg,std::string message)
	:Interactable(chestImg,message,"Chest")
	{
		isOpen=false;
		i=NULL;
	}
	explicit Chest(std::string chestImg, std::string message,Item * i)
	:Interactable(chestImg,message,"Chest")
	{
			this->i=i;
			isOpen=false;
	}

	Item * getItem(){
		if(isOpen){
			Item * temp=i;
			i=0;
			return temp;
		}else
			return 0;

	}
	void setItem(Item * i){
		this->i=i;
	}
	void open(){
		isOpen=true;
		if(i!=NULL){
			i->setPosition(this->getSprite().getPosition().x,this->getSprite().getPosition().y);
			i->setIsLoaded(true);
		}
	}

};
