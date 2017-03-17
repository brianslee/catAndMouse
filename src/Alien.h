#ifndef ALIEN_H_
#define ALIEN_H_

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "character.h"

class Alien : Character
{
public:
	Alien(sf::Vector2i initPos, int v, int s);
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
	sf::Texture alienTexture;
};
#endif