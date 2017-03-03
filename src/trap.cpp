
#include "trap.h"


	 void trap::activate(Human * a){
		
	}

	bool trap::getIsDeployed(){
		return isDeployed;
	}

	void trap::setIsDeployed(bool isDeployed){
		this->isDeployed=isDeployed;
	}

	void trap::placeTrap(Human a){
		this->setPosition(a.getPos().x+50,a.getPos().y);
		this->setIsLoaded(true);
		this->setIsDeployed(true);

	}


