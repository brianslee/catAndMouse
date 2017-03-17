#include "Table.h"

Table::Table(int visibility)
:hidingPlace("Spritesheets/Desk1.png","A computer on a desk","Table",0.4,visibility)
{
	this->setRect(0,0,648,648);
	this->getSprite().setScale(scaleFactor-0.05,scaleFactor);
}

Table::Table(std::string img, std::string message,float scale, int visibility)
:hidingPlace(img,message,"Table",scale,visibility){}

void Table::hide(Human * a){
	if(a->distanceToInteractable(this)<dis){
		if(!this->getIsOccupied()){
			this->setIsOccupied(true);
			a->setSight(this->getVisibility());
			this->updateSprite(0,1);
			a->setIsLoaded(false);
			a->setSpeed(0);
		}else{
			this->setIsOccupied(false);
			a->setSight(3);
			this->updateSprite(0,0);
			a->setIsLoaded(true);
			a->setSpeedToOriginal();
		}
	}
}

sf::Vector2f Table::getPos(){
	 //get the center point of the sprite.
	sf::Vector2f vect(sprite.getPosition().x+this->spriteX*scaleFactor/2.7,
			sprite.getPosition().y+this->spriteY*scaleFactor/1.5);
	return vect;
}
