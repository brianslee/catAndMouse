
#include "stickyTrap.h"

	float stickyTrap::getDuration(){
		return duration;
	}

	float stickyTrap::getActivatedTime() {
		return activatedTime;
	}

	void stickyTrap::setActivatedTime(float activatedTime) {
		this->activatedTime = activatedTime;
	}

	void stickyTrap::activate(Human * a,float currentTime){
		this->activated=true;
		if(activatedTime==-1)
			activatedTime=currentTime;
		if((currentTime-activatedTime)<duration){
			a->setSpeed(0);
			a->setCanRotate(false);
			a->setCanAttack(false);
		}else{
			a->setCanRotate(true);
			a->setCanAttack(true);
			a->setSpeedToOriginal();
			activatedTime=-1;
			activated=false;
			trap::afterActivated();
		}
	}

