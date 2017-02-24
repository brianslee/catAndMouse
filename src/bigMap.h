

#ifndef bigMap_h
#define bigMap_h


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.h"

class bigMap {
    public:

        bigMap(int sz=15);
        
        //Get the size of the map
        int getSize();
        
        // return the map sprite
        sf::Drawable& getSprite();
        
        // return the shadow sprite at x,y coordinate
        sf::Drawable& getShade(int x, int y);
        
        // return if grid(x,y) is a wall
        bool getWall(int x, int y);
        
        // initialize the map with an image for locating everything
        void load(sf::Image &image);
        
        // update FoW with current char Position and char sight 
        void updateShade(sf::Vector2i pos, int sight);

		// get the detection status
    	int getDetect(int x, int y);
    
    private:
        int size = 15;
        grid** Map;
        int** isDetected;
        sf::Sprite background;
};


#endif /* bigMap_h */
