#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "Alien.h"
#include "character.h"
#include "chest.h"
#include "entity.h"
#include "interactable.h"
#include "HealthBar.h"
#include "locker.h"
#include "Table.h"
#include "trap.h"

Alien::Alien(sf::Vector2i initPos, int v, int s)
{
	Character(initPos, v, s);
	spriteCounter = 0;
	spriteNum = 4;
	spriteLength = 215;
	spriteWidth = 215;
	alienTexture.loadFromFile("Spritesheets/Alien_1_Movement2-1.png");
}

bool Alien::isMarine()
{
	return false;
}

bool Alien::isAlien()
{
	return false;
}

int Alien::getSpriteCounter()
{
	return spriteCounter;
}

int Alien::getSpriteNum()
{
	return spriteNum;
}

int Alien::getSpriteLength()
{
	return spriteLength;
}

int Alien::getSpriteWidth()
{
	return spriteWidth;
}