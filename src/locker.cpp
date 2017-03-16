#include "locker.h"

locker::locker(std::string img, std::string message,float scale, int visibility)
:hidingPlace(img,message,"Locker",scale,visibility),doorOpen(false){}

locker::locker(int visibility)
:hidingPlace("Spritesheets/locker_combined.png","Looks safe","Locker",0.35,visibility),doorOpen(false)
{
	this->setRect(0,0,648,648);
	this->getSprite().setScale(scaleFactor,scaleFactor-0.07);
	this->updateSprite(0,1);
}

bool locker::getDoorOpen(){
	return this->doorOpen;
}


void locker::open(Character* a){
	doorOpen=true;

	if(a->distanceToInteractable(this)<dis){
		a->setSight(3);
		a->setCanAttack(true);
		a->setIsLoaded(true);
		a->setSpeedToOriginal();

	}
}

void locker::close(Character* a){
	doorOpen=false;
	if(a->distanceToInteractable(this)<dis){
		this->setIsOccupied(true);
		a->setSight(this->getVisibility());
		a->setCanAttack(false);
		a->setIsLoaded(false);
		a->setSpeed(0);
	}else{
		this->setIsOccupied(false);

	}
}

sf::Vector2f locker::getPos(){
	 //get the center point of the sprite.
	sf::Vector2f vect(sprite.getPosition().x+this->spriteX*scaleFactor/2,
			sprite.getPosition().y+this->spriteY*scaleFactor/1.8);
	return vect;
}

void locker::animation(){
	int startY,endY;
	if(doorOpen){
		startY=1;
		endY=6;
		if(isOccupied)
			startY--;
	}else{
		startY=6;
		endY=1;
		if(isOccupied)
			endY--;
	}
	interactable::animation(0,0,startY,endY,false,0.05);
}

