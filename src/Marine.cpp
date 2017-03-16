#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "Marine.h"
#include "character.h"
#include "chest.h"
#include "entity.h"
#include "interactable.h"
#include "HealthBar.h"
#include "locker.h"
#include "Table.h"
#include "trap.h"

Marine::Marine(sf::Vector2i initPos, int v, int s)
{
	Character(initPos, v, s);
	spriteCounter = 0;
	spriteNum = 9;
	spriteLength = 216;
	spriteWidth = 216;
	marineTexture.loadFromFile("Spritesheets/Space_Marine1-2.png");
	setupSprite(marineTexture, 280, 440, spriteLength, spriteWidth);
}

bool Marine::isMarine()
{
	return true;
}

bool Marine::isAlien()
{
	return false;
}

int Marine::getSpriteCounter()
{
	return spriteCounter;
}

int Marine::getSpriteNum()
{
	return spriteNum;
}

int Marine::getSpriteLength()
{
	return spriteLength;
}

int Marine::getSpriteWidth()
{
	return spriteWidth;
}