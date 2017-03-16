

#ifndef INTERACTABLEMANAGER_H_
#define INTERACTABLEMANAGER_H_
#include <SFML/Graphics.hpp>
#include <typeinfo>

#include "damageTrap.h"
#include "stickyTrap.h"
#include "chest.h"
#include "locker.h"
#include "Table.h"

class InteractableManager {
private:
	std::vector<interactable *> gameInteractable;
	std::vector<chest *> gameChests;
	std::vector<hidingPlace *> gameHidingPlaces;
	std::vector<trap *> gameTraps;

public:
	InteractableManager(){}

	void add(interactable * mInteractable);

	void notifyTrapsDeployed();

	void remove(std::string type);

	void drawAll(sf::RenderWindow& window);

	void startAnimation();

	void trapsDetection(Human * a,float currentTime);

	std::vector<interactable *> getIAList();

	std::vector<trap *> getTrapsList();


};

#endif /* INTERACTABLEMANAGER_H_ */
