//
//  grid.hpp
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef grid_hpp
#define grid_hpp

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <iostream>

class grid {
public:
    grid();
    void setShade(int num);
    void setWall(bool b);
    bool getWall();
    sf::RectangleShape& getShade();
    
    
    
private:
    sf::RectangleShape shade = sf::RectangleShape(sf::Vector2f(80.0, 80.0));
    bool isWall;
    //    int type; //preserved for later;
    
    
};


#endif /* grid_hpp */
