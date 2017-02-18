//
//  bigMap.hpp
//  F48
//
//  Created by James wang on 2/18/17.
//  Copyright © 2017 James wang. All rights reserved.
//

#ifndef bigMap_hpp
#define bigMap_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "grid.hpp"

class bigMap {
    public:
        bigMap();
        int getSize();
        sf::Drawable& getSprite();
        sf::Drawable& getShade(int x, int y);
        bool getWall(int x, int y);
        void load(sf::Image &image);
        void updateShade(sf::Vector2i pos, int sight);

    
    
    private:
        int size = 15;
        grid** Map;
        int isDetected[14][14];
        sf::Sprite background;
};


#endif /* bigMap_hpp */
