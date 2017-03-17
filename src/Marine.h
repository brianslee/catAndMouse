#ifndef MARINE_H_
#define MARINE_H_

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "character.h"
#include "chest.h"
#include "entity.h"
#include "interactable.h"
#include "HealthBar.h"

class Marine : Character
{
public:
	//Constructor
	Marine(sf::Vector2i initPos, int v, int s);
	//Public functions
	bool isMarine();
	bool isAlien();

	//Getters
	int getSpriteCounter();
	int getSpriteNum();
	int getSpriteLength();
	int getSpriteWidth();
	void updateCoor();

private:
	int spriteCounter;
	int spriteNum;
	int spriteLength;
	int spriteWidth;
	sf::Texture marineTexture;
	sf::Clock marineClock;
};
#endif