#include "damageTrap.h"

	int damageTrap::getDamagePoint(){
		return damagePoint;
	}


	void damageTrap::activate(Character * a){
		this->activated=true;
		a->setHP(a->getHP()-damagePoint);
		trap::afterActivated();
		std::cout<<"Activited, player HP:"<<a->getHP()<<std::endl;
	}


