#include "locker.h"

locker::locker(std::string img, std::string message,float scale, int visibility)
:hidingPlace(img,message,"Locker",scale,visibility),doorOpen(false){}

locker::locker(int visibility)
:hidingPlace("Spritesheets/lockerA.png","Looks safe","Locker",0.35,visibility),doorOpen(false)
{
	this->setRect(0,0,648,648);
	this->getSprite().setScale(scaleFactor,scaleFactor-0.07);
}

bool locker::getDoorOpen(){
	return this->doorOpen;
}

void locker::open(Human * a){
	doorOpen=true;
	if(spriteX!=0)
		this->updateSprite(0,4);
	if(a->distanceToInteractable(this)<dis){
		a->setSight(3);
		a->setIsLoaded(true);
		a->setSpeedToOriginal();
	}
}

void locker::close(Human* a){
	doorOpen=false;
	if(a->distanceToInteractable(this)<dis){
		this->setIsOccupied(true);
		a->setSight(this->getVisibility());
		this->updateSprite(0,6);
		a->setIsLoaded(false);
		a->setSpeed(0);
	}else{
		this->setIsOccupied(false);
//		a->setSight(3);
		this->updateSprite(0,0);

	}
}

sf::Vector2f locker::getPos(){
	 //get the center point of the sprite.
	sf::Vector2f vect(sprite.getPosition().x+this->spriteX*scaleFactor/2,
			sprite.getPosition().y+this->spriteY*scaleFactor/1.8);
	return vect;
}

