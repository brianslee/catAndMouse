#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <typeinfo>


#include "bigMap.h"
#include "chest.h"
#include "entity.h"
#include "interactable.h"
#include "HealthBar.h"

class Character : public entity
{
    protected:
    sf::Vector2i position;
    sf::Sprite sprite_original;
    int originalSpeed;
    int speed;
    int sight;
    const static int dis = 70;
    bool isLoaded;
    HealthBar hp;
    bool canRotate;
    bool canAttack;
    int spriteCounter;
    int spriteNum;
    int spriteLength;
    int spriteWidth;
    
    public:
    //Public Members
    int movementSpeed = 4;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0;
    int counter = 0;
    bool alive = true;
    bool isAlien = false;
    bool isMarine = false;
    bool isTerm = false;
    
    //Public Functions
    //Constructor
    Character(sf::Vector2i initPos, int v, int s);

    void setCharacter(bool marine);

    //sets up the sprite to the correct texture and position
    void setupSprite(sf::Texture& texture, int x, int y);
    
    // Rotate the character direction to mouse direction
    void updateRotation(sf::View& view, sf::RenderWindow& window);
    
    // Check if moving towards dir is legal
    bool checkAccess(int dir, bigMap& map);
    
    // Update character sprite for animations
    int updateSprite(sf::RenderWindow& window, sf::Clock& clock);
    
    // update the position of the sprite
    void update();
    
    //Getters/Setters
    bool getIsMarine();
    bool getIsAlien();

    int getSpriteCounter();
    int getSpriteNum();
    int getSpriteLength();
    int getSpriteWidth();
    
    //get the sprite
    sf::Sprite& getSprite();
    
    //get the coordinate of the character
    sf::Vector2i getCoor();
    
    //get the aiming angle of the character
    float getAngle(sf::View& view, sf::RenderWindow& window);
    
    // get the speed
    int getSpeed();
    
    //get the original movement speed
    int getOriginalSpeed();
    
    //get the sight
    int getSight();
    
    //get current position of the sprite
    sf::Vector2f getPos();
    
    bool isIsLoaded();
    
    bool isCanAttack();
    
    bool isCanRotate();
    
    //set the coordinate of character
    void setCoor(sf::Vector2i coor);
    
    //set the movement speed
    void setSpeed(int v);
    
    //Change back to original movement speed
    void setSpeedToOriginal();
    
    //set the sight
    void setSight(int s);
    
    //make the coordinate of character match with position of sprite
    void updateCoor();
    
    //move in dir direction
    void walk(int dir);
    
    //set a new position (relative to the map)
    void setPos(const sf::Vector2f& pos);
    
    void setIsLoaded(bool isLoaded);
    
    void setCanAttack(bool canAttack);
    
    void setCanRotate(bool canRotate);
    
    //Game Related Code
    HealthBar* getHPBar();
    
    int getHP();
    
    void setHP(int hp);

    void setHPBar(HealthBar hpb);


    //get the distance between the interactables and the player
    int distanceToInteractable(interactable* item);     
    
    //Inspect the interactables that is closest to the player , which will gives a message about it
    void inspect(std::vector<interactable*> itemsList); 
    
    //React with the interactables that is closest to the player
    std::string react(std::vector<interactable*> itemsList);

    //void upgradeSprite(sf::Texture& texture, int nSpriteCounter, int nSpriteNum, int nSpriteWidth, int nSpriteLength, bool term);
};
#endif