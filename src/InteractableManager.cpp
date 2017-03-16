

#include "InteractableManager.h"

void InteractableManager::add(interactable * mInteractable){
//		gameInteractable.push_back(mInteractable);
		gameInteractable.insert(gameInteractable.begin(),mInteractable);
		std::string type=mInteractable->getType();
		if(type=="DamageTrap"||type=="StickyTrap"){
			trap* tp=dynamic_cast<trap*>(mInteractable);
			gameTraps.push_back(tp);
		}
		if(type=="Table"||type=="Locker"){
			hidingPlace* hp=dynamic_cast<hidingPlace*>(mInteractable);
			gameHidingPlaces.push_back(hp);
		}
		if(type=="Chest"){
			chest* ch=dynamic_cast<chest*>(mInteractable);
			gameChests.push_back(ch);
		}
}


void InteractableManager::remove(std::string name){

}

void InteractableManager::drawAll(sf::RenderWindow& window){
//	std::map<std::string,interactable *>::const_iterator itr=gameInteractable.begin();
	std::vector<interactable *>::iterator itr=gameInteractable.begin();
	while(itr !=gameInteractable.end()){
		(*itr)->draw(window);
		itr++;
	}
}

void InteractableManager::startAnimation(){
	std::vector<trap*>::iterator trap_itr=gameTraps.begin();
	while(trap_itr!=gameTraps.end()){
		(*trap_itr)->animation();
		trap_itr++;
	}
	std::vector<hidingPlace*>::iterator hp_itr=gameHidingPlaces.begin();
	while(hp_itr!=gameHidingPlaces.end()){
		if((*hp_itr)->getType()=="Locker"){
			locker * lo=dynamic_cast<locker*>(*hp_itr);
			lo->animation();
		}
		hp_itr++;
	}
}

void InteractableManager::trapsDetection(Character* a,float currentTime){
	std::vector<trap*>::iterator trap_itr=gameTraps.begin();
	while(trap_itr!=gameTraps.end()){
		if((*trap_itr)->getIsLoaded()&&(*trap_itr)->getIsDeployed()){
			if(a->distanceToInteractable(*trap_itr)<25){
				if((*trap_itr)->getType()=="StickyTrap"){
					stickyTrap* st=dynamic_cast<stickyTrap*>(*trap_itr);
					st->activate(a,currentTime);
				}else{
					damageTrap* dt=dynamic_cast<damageTrap*>(*trap_itr);
					dt->activate(a);
				}
			}
		}
		trap_itr++;
	}
}

void InteractableManager::notifyTrapsDeployed(Network* network){

}

// Update the hiding place list through network
void InteractableManager::notifyHidingPlacesActions(Network* network){

}

// Update the chest list through network
void InteractableManager::notifyChestsOpen(Network* network){

}

void InteractableManager::receiveNotificaton(Network* network){
	short typeChanged;
	network->receiveIATypeChanged(typeChanged);
}

std::vector<interactable *> InteractableManager::getIAList(){
	return gameInteractable;
}

//std::vector<trap *> InteractableManager::getTrapsList(){
//	return gameTraps;
//}


//std::map<std::string,interactable *> InteractableManager::getIAList(){
//	return this->gameInteractable;
//}
//
//
//std::map<trap *> InteractableManager::getTrapsList(){
//	return this->gameTraps;
//}

