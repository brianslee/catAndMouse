

#ifndef INTERACTABLEMANAGER_H_
#define INTERACTABLEMANAGER_H_
#include <SFML/Graphics.hpp>
//#include "interactable.h"
#include "trap.h"
#include "hidingPlace.h"
#include "item.h"

class InteractableManager {
private:
	std::map<std::string,interactable *> gameInteractable;
	std::map<std::string,chest *> gameChests;
	std::map<std::string,hidingPlace *> gameHidingPlaces;
	std::map<std::string,Item *> gameItems;
	std::map<std::string,trap *> gameTraps;
public:
	InteractableManager(){}

	void add(std::string name, interactable * mInteractable);

	void notifyTrapsDeployed();

	void remove(std::string name);

	void drawAll(sf::RenderWindow& window);

	std::map<std::string,interactable *> getIAList();

	std::map<std::string,trap *> getTrapList();


};

#endif /* INTERACTABLEMANAGER_H_ */
