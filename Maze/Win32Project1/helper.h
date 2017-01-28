#pragma once
#include "character.h"
#include "grid.h"

//Check if dir direction is accessible
//Return 1 if accessible
bool checkAccess(Character::Human a, int dir,bigMap map) {
	if (int(a.getPos().x) % 80 > 20 && int(a.getPos().y) % 80 > 20)return true;
	if (int(a.getPos().x) % 80 <= 15 && int(a.getPos().y) % 80 > 20) {
		if (dir == 0 || dir == 1)return true;
		else if (dir == 2 && int(a.getPos().x) <= 5)return !(map.getWall(a.getCoor().x - 1, a.getCoor().y + 1) | map.getWall(a.getCoor().x - 1, a.getCoor().y));
		else if (dir == 3 && int(a.getPos().x) >= 15)return !(map.getWall(a.getCoor().x + 1, a.getCoor().y + 1) | map.getWall(a.getCoor().x + 1, a.getCoor().y));
		else return true;
	}
	if (int(a.getPos().x) % 80 > 20 && int(a.getPos().y) % 80 <= 20) {
		if (dir == 2 || dir == 3)return true;
		else if (dir == 0 && int(a.getPos().y) <= 5)return !(map.getWall(a.getCoor().x, a.getCoor().y - 1) | map.getWall(a.getCoor().x + 1, a.getCoor().y - 1));
		else if (dir == 1 && int(a.getPos().y) >= 15)return !(map.getWall(a.getCoor().x, a.getCoor().y + 1) | map.getWall(a.getCoor().x + 1, a.getCoor().y + 1));
		else return true;
	}
	if (int(a.getPos().x) % 80 <= 5 && dir == 2)return !map.getWall(a.getCoor().x - 1, a.getCoor().y);
	if (int(a.getPos().x) % 80 >= 15 && dir == 3)return !map.getWall(a.getCoor().x + 1, a.getCoor().y);
	if (int(a.getPos().y) % 80 <= 5 && dir == 0)return !map.getWall(a.getCoor().x, a.getCoor().y - 1);
	if (int(a.getPos().y) % 80 >= 15 && dir == 1)return !map.getWall(a.getCoor().x, a.getCoor().y + 1);

	return 1;
}