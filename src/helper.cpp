//
//  helper.cpp
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "helper.h"


sf::Vector2f getCenter(sf::Vector2f vec, sf::Vector2u mapSize) {
    double tx = vec.x, ty = vec.y;
    if (400.0 > tx)tx = 400;
    else if (tx > mapSize.x - 400)tx = double(mapSize.x - 400);
    if (400.0 > ty)ty = 400;
    else if (ty > mapSize.y - 400)ty = double(mapSize.y - 400);
    return sf::Vector2f(tx, ty);
}