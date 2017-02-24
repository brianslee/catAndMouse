

#ifndef grid_h
#define grid_h

#include <stdio.h>

#include <SFML/Graphics.hpp>
#include <iostream>

class grid {
public:
    grid();
    // set the shade level of the current grid
    void setShade(int num);
    
    // set if the grid is a wall
    void setWall(bool b);
    
    // get wall status of the grid
    bool getWall();
    
	// get the sprite for the block
	sf::RectangleShape& getShade();
    
    
    
private:
    sf::RectangleShape shade = sf::RectangleShape(sf::Vector2f(80.0, 80.0));
    bool isWall;
    //    int type; //preserved for later;
    
    
};


#endif /* grid_h */
