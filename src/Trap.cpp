
#include "Trap.h"


	 void Trap::activate(Human * a){
		
	}

	bool Trap::getIsDepolyed(){
		return isDepolyed;
	}

	void Trap::setIsDepolyed(bool isDepolyed){
		this->isDepolyed=isDepolyed;
	}

	void Trap::placeTrap(Human a){
		this->setPosition(a.getPos());
		this->setIsLoaded(true);
		//this->setIsDepolyed(true);

	}


