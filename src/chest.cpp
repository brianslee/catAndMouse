#include "chest.h"

	bool chest::getIsOpen(){
		return isOpen;
	}

	Item * chest::getItem(){
		if(isOpen){
			Item * temp=i;
			i=0;
			return temp;
		}else
			return 0;

	}
	void chest::setItem(Item * i){
		this->i=i;
	}
	void chest::open(){
		isOpen=true;
		if(i!=NULL){
			i->setPosition(
					this->getSprite().getPosition().x+this->spriteX,
					this->getSprite().getPosition().y+this->spriteY);
			i->setIsLoaded(true);
		}
		if(spriteX!=0)
			this->updateSprite(0,1);
	}




