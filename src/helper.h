#pragma once
#pragma once

//This file contains some helper functions for the main function;
//correct is for determining the view center
//returns a sf::Vector2f storing the center coordinate
//checkAccess is for checking if dir direction is accessible
//Return 1 if accessible

#include "character.h"
#include "grid.h"
#include <iostream>
sf::Vector2f getCenter(sf::Vector2f vec, sf::Vector2u mapSize) {
	double tx = vec.x, ty = vec.y;
	if (400.0 > tx)tx = 400;
	else if (tx > mapSize.x - 400)tx = double(mapSize.x - 400);
	if (400.0 > ty)ty = 400;
	else if (ty > mapSize.y - 400)ty = double(mapSize.y - 400);
	return sf::Vector2f(tx, ty);
}

bool checkAccess(Human a, int dir, bigMap map) {

	// human is standing on 4 grids
	if (int(a.getPos().x) % 80 >= 20 && int(a.getPos().y) % 80 >= 20)return true;

	// human is standing on 2 grids
	// horizontal
	else if ((int(a.getPos().x) % 80 >= 20) && (int(a.getPos().y) % 80 <= 20)) {
		if (dir == 0 && (int(a.getPos().y) % 80 <= 5))
			return !(map.getWall(a.getCoor().x, a.getCoor().y - 1) || map.getWall(a.getCoor().x + 1, a.getCoor().y - 1));
		else if (dir == 1 && (int(a.getPos().y) % 80 >= 15))
			return !(map.getWall(a.getCoor().x, a.getCoor().y + 1) || map.getWall(a.getCoor().x + 1, a.getCoor().y + 1));
		else return 1;
	}
	// vertical
	else if ((int(a.getPos().y) % 80 >= 20) && (int(a.getPos().x) % 80 <= 20)) {
		if (dir == 2 && (int(a.getPos().x) % 80 <= 5))
			return !(map.getWall(a.getCoor().x - 1, a.getCoor().y) || map.getWall(a.getCoor().x - 1, a.getCoor().y + 1));
		else if (dir == 3 && (int(a.getPos().x) % 80 >= 15))
			return !(map.getWall(a.getCoor().x + 1, a.getCoor().y) || map.getWall(a.getCoor().x + 1, a.getCoor().y + 1));
		else return 1;
	}

	// human is standing on 1 grid
	else if (int(a.getPos().x) % 80 <= 5 && dir == 2)return !map.getWall(a.getCoor().x - 1, a.getCoor().y);
	else if (int(a.getPos().x) % 80 >= 15 && dir == 3)return !map.getWall(a.getCoor().x + 1, a.getCoor().y);
	else if (int(a.getPos().y) % 80 <= 5 && dir == 0)return !map.getWall(a.getCoor().x, a.getCoor().y - 1);
	else if (int(a.getPos().y) % 80 >= 15 && dir == 1)return !map.getWall(a.getCoor().x, a.getCoor().y + 1);

	return 1;
}


