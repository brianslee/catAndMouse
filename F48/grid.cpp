//
//  grid.cpp
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#include "grid.hpp"


grid::grid() {
    isWall = true;
    shade.setFillColor(sf::Color::Black);
}
void grid::setShade(int num) {
    switch (num)
    {
        case 0:
            shade.setFillColor(sf::Color(0, 0, 0, 255));
            break;
        case 1:
            shade.setFillColor(sf::Color(0, 0, 0, 127));
            break;
        case 2:
            shade.setFillColor(sf::Color(0, 0, 0, 0));
            break;
        default:
            break;
    }
}


void grid::setWall(bool b)
    {
        isWall = b;
    }


bool grid::getWall()
    {
        return isWall;
    }


sf::RectangleShape& grid:: getShade()
    {
        return shade;
    }

