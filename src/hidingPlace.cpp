#include "hidingPlace.h"

	hidingPlace::hidingPlace(std::string img,std::string message,std::string type,float scale,int visibility)
		:interactable(img,message,type,scale),visibility(visibility),isOccupied(false){

	}

	int hidingPlace::getVisibility(){
		return this->visibility;
	}

	bool hidingPlace::getIsOccupied(){
		return this->isOccupied;
	}

	void hidingPlace::setIsOccupied(bool io){
		this->isOccupied=io;
		animation();
	}
