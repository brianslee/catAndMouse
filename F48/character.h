
#ifndef STUDENT_H
#define STUDENT_H

#include <SFML/Graphics.hpp>
#include <utility>
#include"entity.hpp"


class Human:public entity{
        
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
    
    private:
        sf::Vector2i position;
        sf::Sprite sprite_original;
        int speed;
        int sight;
    
    
};
#endif
