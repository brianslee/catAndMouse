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

bool checkAccess(Human& a, int dir, bigMap& map) {
    
    // human is standing on 4 grids
    if (int(a.getPos().x) % 80 > 50 && int(a.getPos().y) % 80 > 50)return true;
    
    // human is standing on 2 grids
    // horizontal
    else if ((int(a.getPos().x) % 80 > 50) && (int(a.getPos().y) % 80 <= 50)) {
        if (dir == 0 && (int(a.getPos().y) % 80 <= 35))
            return !(map.getWall(a.getCoor().x, a.getCoor().y - 1) || map.getWall(a.getCoor().x + 1, a.getCoor().y - 1));
        else if (dir == 1 && (int(a.getPos().y) % 80 >= 45))
            return !(map.getWall(a.getCoor().x, a.getCoor().y + 1) || map.getWall(a.getCoor().x + 1, a.getCoor().y + 1));
        else return 1;
    }
    // vertical
    else if ((int(a.getPos().y) % 80 > 50) && (int(a.getPos().x) % 80 <= 50)) {
        if (dir == 2 && (int(a.getPos().x) % 80 <= 45))
            return !(map.getWall(a.getCoor().x - 1, a.getCoor().y) || map.getWall(a.getCoor().x - 1, a.getCoor().y + 1));
        else if (dir == 3 && (int(a.getPos().x) % 80 >= 45))
            return !(map.getWall(a.getCoor().x + 1, a.getCoor().y) || map.getWall(a.getCoor().x + 1, a.getCoor().y + 1));
        else return 1;
    }
    
    // human is standing on 1 grid
    else if (int(a.getPos().x) % 80 <= 35 && dir == 2)return !map.getWall(a.getCoor().x - 1, a.getCoor().y);
    else if (int(a.getPos().x) % 80 >= 45 && dir == 3)return !map.getWall(a.getCoor().x + 1, a.getCoor().y);
    else if (int(a.getPos().y) % 80 <= 35 && dir == 0)return !map.getWall(a.getCoor().x, a.getCoor().y - 1);
    else if (int(a.getPos().y) % 80 >= 45 && dir == 1)return !map.getWall(a.getCoor().x, a.getCoor().y + 1);
    
    return 1;
}

void updateRotation(Human& player, sf::View& view, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f charPos = player.getPos();
    sf::Vector2f windowPos = view.getCenter();
    charPos.x += 30;
    charPos.y += 30;
    windowPos.x -= 400;
    windowPos.y -= 400;
    
    //	std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
    //	std::cout << atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159 << std::endl;
    sf::Transform transform;
    
    player.getSprite().setRotation(-atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159);
    
    
}

int updateSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter) {
    if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
        sprite.setTextureRect(sf::IntRect(((spriteCounter) % 2)*spriteLength, (spriteCounter / 2)*spriteWidth, ((spriteCounter) % 2 + 1)*spriteLength, (spriteCounter / 2 + 1)*spriteWidth));
        sprite.setScale(60.0 / (double)(spriteLength), 60.0 / (double)(spriteWidth));
        window.draw(sprite);
        clock.restart();
        spriteCounter = (spriteCounter + 1) % spriteNum;
    }
    return spriteCounter;
}

int updateMarineSprite(sf::Sprite& sprite, sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter)
{
    if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
        sprite.setTextureRect(sf::IntRect(sf::IntRect(0, (spriteCounter) * spriteLength, spriteLength, spriteWidth)));
        sprite.setScale(60.0 / (double)(spriteLength), 60.0 / (double)(spriteWidth));
        window.draw(sprite);
        clock.restart();
        spriteCounter = (spriteCounter + 1) % spriteNum;
    }
    return spriteCounter;
}