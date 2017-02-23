#include "Chest.h"

	bool Chest::getIsOpen(){
		return isOpen;
	}

	Item * Chest::getItem(){
		if(isOpen){
			Item * temp=i;
			i=0;
			return temp;
		}else
			return 0;

	}
	void Chest::setItem(Item * i){
		this->i=i;
	}
	void Chest::open(){
		isOpen=true;
		if(i!=NULL){
			i->setPosition(this->getSprite().getPosition().x,this->getSprite().getPosition().y);
			i->setIsLoaded(true);
		}
	}


