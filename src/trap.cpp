
#include "trap.h"


	 void trap::activate(Human * a){
		
	}

	bool trap::getIsDepolyed(){
		return isDepolyed;
	}

	void trap::setIsDepolyed(bool isDepolyed){
		this->isDepolyed=isDepolyed;
	}

	void trap::placeTrap(Human a){
		this->setPosition(a.getPos());
		this->setIsLoaded(true);
		//this->setIsDepolyed(true);

	}


