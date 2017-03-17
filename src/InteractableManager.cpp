

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
}


void InteractableManager::remove(std::string name){

}

void InteractableManager::drawAll(sf::RenderWindow& window){
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

bool InteractableManager::trapsDetection(Character* a,float currentTime){
	bool result=false;
	std::vector<trap*>::iterator trap_itr=gameTraps.begin();
	while(trap_itr!=gameTraps.end()){
		if((*trap_itr)->getIsLoaded()&&(*trap_itr)->getIsDeployed()){
			if(a->distanceToInteractable(*trap_itr)<25){
				result=true;
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
	return result;
}

//void InteractableManager::notifyTrapsDeployed(Network* network){
//	network->sendIATypeChanged(3);
//}
//
//void InteractableManager::notifyHidingPlacesActions(Network* network){
//
//}
//
//void InteractableManager::notifyChestsOpen(Network* network){
//
//}
//
//void InteractableManager::receiveNotificaton(Network* network){
//	short typeChanged;
//	network->receiveIATypeChanged(typeChanged);
//}

std::vector<interactable *> InteractableManager::getIAList(){
	return gameInteractable;
}


