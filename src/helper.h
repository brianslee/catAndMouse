#ifndef helper_h
#define helper_h
#pragma once
#include "character.h"
//#include "grid.hpp"
#include "bigMap.h"
#include <iostream>
#include <cmath>
#include "alienattack.h"
#include <stdio.h>

// Get center coordinates for the window
sf::Vector2f getCenter(sf::Vector2f vec, sf::Vector2u mapSize);

// Check if moving towards dir is legal
bool checkAccess(Human& a, int dir, bigMap& map);

// Rotate the character direction to mouse direction
void updateRotation(Human& player, sf::View& view, sf::RenderWindow& window);

// Update character sprite for animations
int updateSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter);

<<<<<<< HEAD
// Update marine sprite animation
// Why do we need two identical func?
//int updateMarineSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter);
=======
int updateMarineSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter);
>>>>>>> origin/master


#endif /* helper_h */
