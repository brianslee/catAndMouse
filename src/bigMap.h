//
//  bigMap.h
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef bigMap_h
#define bigMap_h


#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "grid.h"

class bigMap {
    public:
    
    //Constructor 
        bigMap();
    
    //Get the size of the map
        int getSize();
    
    //Get the map sprite and returns a Drawable object
        sf::Drawable& getSprite();
    //Get the shade of the map, which is used for Fog of War returns a Drawable object
        sf::Drawable& getShade(int x, int y);
    //Check if the wall is there
        bool getWall(int x, int y);
    //Load the map
        void load(sf::Image &image);
    //Update the fog of war, passing in position and the position to see it     
    void updateShade(sf::Vector2i pos, int sight);

    
    
    private:
        int size = 15;
        grid** Map;
        int isDetected[14][14];
        sf::Sprite background;
};


#endif /* bigMap_h */
