
#include "trap.h"
#include <math.h>

	 void trap::activate(Human * a){
		 this->setIsDeployed(false);
		 this->setIsLoaded(false);
	}

	bool trap::getIsDeployed(){
		return isDeployed;
	}

	void trap::setIsDeployed(bool isDeployed){
		this->isDeployed=isDeployed;
	}

	void trap::placeTrap(Human * a,sf::View& view, sf::RenderWindow& window){
		float dis=45.f;
		float angle=a->getAngle(view,window);
		float distX=dis*cos((3.14159/180)*angle);
		float distY=dis*sin((3.14159/180)*angle);
		float playerPosX=a->getPos().x-26;
		float playerPosY=a->getPos().y-26;

		this->setPosition(playerPosX+distX,playerPosY+distY);

		this->updateSprite(0,1);
		this->setIsLoaded(true);
		this->setIsDeployed(true);
	}

	void trap::animation(){
		int startY,endY;
		if(curGridY==0){
			startY=0;
			endY=1;
		}else{
			startY=1;
			endY=0;
		}
		interactable::animation(0,0,startY,endY,false,0.5);
	}

