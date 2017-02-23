#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <vector>
#include <typeinfo>

#include "chest.h"
#include "entity.h"
#include "interactable.h"


class Human:public entity{
 private:
 	sf::Vector2i position;
 	sf::Sprite sprite_original;
 	int speed;
 	int sight;
       
 public:
    int movementSpeed = 4 ;
    int attackDamage = 5;
    int counterWalking = 0;
    int direction = 0;
    int counter = 0;
    int hp = 5;
    bool alive = true;
    
    void update();
    //void updateMovement();
        
    Human(sf::Vector2i initPos, int v, int s);
    
    sf::Sprite& getSprite();
    sf::Vector2i getCoor();
    int getSpeed();
    int getSight();
    sf::Vector2f getPos();
    void setCoor(sf::Vector2i coor);
    void setSpeed(int v);
    void setSight(int s);
    void updateCoor();
    void walk(int dir);
    void setPos(const sf::Vector2f& pos);
    int distanceToInteractable(interactable* item);
	void inspect(std::vector<interactable*> itemsList);
	void react(std::vector<interactable*> itemsList);

    
};
#endif

