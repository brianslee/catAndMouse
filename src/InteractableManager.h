

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
	std::vector<hidingPlace *> gameHidingPlaces;
	std::vector<trap *> gameTraps;

public:
	InteractableManager(){}

	// Add the interactable to the InteractableManager.
	void add(interactable * mInteractable);

	// Remove an interactable from the IM that marked for deletion (i.e. Free up memory for an item is used and no longer appear on the map.)
	void remove(std::string type);

	// Draw all Interactable to the window
	void drawAll(sf::RenderWindow& window);

	// Start the animation of the interactable if any.
	void startAnimation();

	// Detect the distance between all the traps and the character to determine should the traps activate.
	bool trapsDetection(Character* a,float currentTime);

	// Update the traps list through network
//	void notifyTrapsDeployed(Network* network);

	// Update the hiding place list through network
//	void notifyHidingPlacesActions(Network* network);

	// Update the chest list through network
//	void notifyChestsOpen(Network* network);

//	void receiveNotificaton(Network* network);
	// Return the vector: gameInteractable
	std::vector<interactable *> getIAList();

//	// Return the vector:
//	std::vector<trap *> getTrapsList();


};

#endif /* INTERACTABLEMANAGER_H_ */
