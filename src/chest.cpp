#include "chest.h"

	chest::chest()
	:interactable("Spritesheets/Crate1.png","A chest","Chest",3),isOpen(false),i(NULL)
	{
		this->setRect(0,0,32,32);
	}

	chest::chest(Item * item)
	:interactable("Spritesheets/Crate1.png","A chest","Chest",3),isOpen(false),i(item)
	{
		this->setRect(0,0,32,32);
	}

	chest::chest(std::string chestImg,std::string message,int scale)
	:interactable(chestImg,message,"Chest",scale),isOpen(false),i(NULL)
	{
		this->setRect(0,0,32,32);
	}

	chest::chest(std::string chestImg, std::string message,Item * item,float scale)
	:interactable(chestImg,message,"Chest",scale),i(item),isOpen(false)
	{
		this->setRect(0,0,32,32);
	}

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




