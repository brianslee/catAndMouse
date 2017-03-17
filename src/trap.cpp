
#include "trap.h"


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

	void trap::placeTrap(Human a){
		this->setPosition(a.getPos().x+50,a.getPos().y);
		this->updateSprite(0,1);
		this->setIsLoaded(true);
		this->setIsDeployed(true);
	}


