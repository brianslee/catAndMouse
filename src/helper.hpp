

#ifndef helper_hpp
#define helper_hpp
#pragma once
#include "character.h"
//#include "grid.hpp"
#include "bigMap.hpp"
#include <iostream>
#include <cmath>
#include "alienattack.hpp"
#include <stdio.h>



//Check if dir direction is accessible
//Return 1 if accessible

sf::Vector2f getCenter(sf::Vector2f vec, sf::Vector2u mapSize);
bool checkAccess(Human& a, int dir, bigMap& map);
void updateRotation(Human& player, sf::View& view, sf::RenderWindow& window);
void updateRotation2(projectile2& shoot, sf::View& view, sf::RenderWindow& window);
int updateSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter);




#endif /* helper_hpp */
