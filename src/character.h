#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <typeinfo>


#include "alienattack.h"
#include "bigMap.h"
#include "chest.h"
#include "entity.h"
#include "interactable.h"
#include "HealthBar.h"


class Character:public entity{
 private:
 	sf::Vector2i position;
 	sf::Sprite sprite_original;
 	int originalSpeed;
 	int speed;
 	int sight;
 	const static int dis=70;
 	bool isLoaded;
	HealthBar hp;
       
 public:
    int movementSpeed = 4 ;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0;
    int counter = 0;
    bool alive = true;

    //BEGIN REFACTOR
    
    void setupSprite(sf::Texture& texture, int x, int y, int spriteLength, int spriteWidth);

    void updateRotation(sf::View& view, sf::RenderWindow& window);

    bool checkAccess(int dir, bigMap& map);

    int updateSprite(sf::RenderWindow& window, sf::Clock& clock , int spriteLength, int spriteWidth, int spriteNum,int spriteCounter);
    
    virtual bool isMarine() {return false;}
    virtual bool isAlien() {return false;}
    //END REFACTOR

    // update the position of the sprite
    void update();
    //void updateMovement();
        
    Character(sf::Vector2i initPos, int v, int s);
    
    // get the sprite
    sf::Sprite& getSprite();
    
    // get the coordinate of the character
    sf::Vector2i getCoor();
    
    //get the aiming angle of the character
    float getAngle(sf::View& view, sf::RenderWindow& window);

    // get the speed
    int getSpeed();
    
    //get the original movement speed
    int getOriginalSpeed();

    // get the sight
    int getSight();
    
    // get current position of the sprite
    sf::Vector2f getPos();
    
    // set the coordinate of character
    void setCoor(sf::Vector2i coor);
    
    // set the movement speed
    void setSpeed(int v);
    
    // Change back to original movement speed
    void setSpeedToOriginal();

    // set the sight
    void setSight(int s);

	//make the coordinate of character match with position of sprite
    void updateCoor();

    // move in dir direction
	void walk(int dir);
    
    // set a new position (relative to the map)
	void setPos(const sf::Vector2f& pos);
	
	HealthBar* getHPBar();
	
	int getHP();
	
	void setHP(int hp);

	void setHPBar(HealthBar hpb);


	//get the distance between the interactables and the player
    int distanceToInteractable(interactable* item);  	
	
	//Inspect the interactables that is closest to the player , which will gives a message about it
	void inspect(std::vector<interactable*> itemsList); 
	
	//React with the interactables that is closest to the player
	void react(std::vector<interactable*> itemsList); 

	bool isIsLoaded();

	void setIsLoaded(bool isLoaded);



};
#endif

