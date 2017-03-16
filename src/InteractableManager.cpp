
#include "InteractableManager.h"

void InteractableManager::add(std::string name, interactable * mInteractable){
	gameInteractable.insert(std::pair<std::string,interactable*>(name,mInteractable));
	std::string type=mInteractable->getType();
	if(type=="DamageTrap"||type=="StickyTrap"){

	}
	if(type=="Table"||type=="Locker"){

	}
	if(type=="Chest"){

	}
}

void InteractableManager::notifyTrapsDeployed(){

}

void InteractableManager::remove(std::string name){

}

void InteractableManager::drawAll(sf::RenderWindow& window){
	std::map<std::string,interactable *>::const_iterator itr=gameInteractable.begin();
	while(itr !=gameInteractable.end()){
		itr->second->draw(window);
		itr++;
	}
}

std::map<std::string,interactable *> InteractableManager::getIAList(){
	return this->gameInteractable;
}


std::map<std::string,trap *> InteractableManager::getTrapList(){
	return this->gameTraps;
}

