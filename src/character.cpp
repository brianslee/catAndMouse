//
//  alien.cpp
//  Attack_48
//
//  Created by James wang on 2/10/17.
//  Copyright © 2017 James wang. All rights reserved.
//
#include "character.h"


Human::Human(sf::Vector2i initPos, int v, int s)
{
    //rect.setSize(sf::Vector2f(300, 300));
    //rect.setPosition(400, 200);
    //rect.setFillColor(sf::Color::Blue);
    //initPos = sf::Vector2i(0, 0);
    v = 8;
    s = 3;
    position = initPos;
	updateCoor();
	speed = v;
    sight = s;
    
}

void Human::update()
{
    sprite.setPosition(rect.getPosition());
}
 

void Human::setPos(const sf::Vector2f& pos)
{
	sprite_original.setPosition(pos);
}

sf::Sprite& Human::getSprite()
{
    return sprite_original;
}
sf::Vector2i Human::getCoor()
{
    return position;
}
int Human::getSpeed()
{
    return speed;
}
int Human::getSight()
{
    return sight;
}
sf::Vector2f Human::getPos()
{
    return sprite_original.getPosition();
}
void Human::setCoor(sf::Vector2i coor)
{
    position = coor; sprite_original.setPosition(80 * coor.x + 40, 80 * coor.y + 40);
}
void Human::setSpeed(int v)
{
    speed = v;
}
void Human::setSight(int s)
{
    sight = s;
}
void Human::updateCoor()
{
    position = sf::Vector2i(int((sprite_original.getPosition().x) / 80.0), int((sprite_original.getPosition().y) / 80.0));
}
void Human::walk(int dir) {
    //map up/down/left/right to 0/1/2/3
    updateCoor();
    switch (dir)
    {
        case 0:
            sprite_original.move(0.0, (float(speed)*(-1)));
            direction = 1;
            break;
        case 1:
            sprite_original.move(0.0, (float(speed)*(1)));
            direction = 2;
            break;
        case 2:
            sprite_original.move(float(speed)*(-1), 0.0);
            direction = 3;
            break;
        case 3:
            sprite_original.move(float(speed)*(1), 0.0);
            direction = 4;
            break;
        default:
            break;
    }
    updateCoor();
}
int Human::distanceToInteractable(interactable* item){
	int x=item->getPos().x-getPos().x;
	int y=item->getPos().y-getPos().y;
	return sqrt(pow(x,2)+pow(y,2));
}
void Human::inspect(std::vector<interactable*> itemsList){
	for(unsigned int i=0;i<itemsList.size();i++){
		if(distanceToInteractable(itemsList[i])<80){
			itemsList[i]->inspect();
		}
	}
}


void Human::react(std::vector<interactable*> itemsList){
	for(unsigned int i=0;i<itemsList.size();i++){
		if(distanceToInteractable(itemsList[i])<80){
			bool itemLoaded=itemsList[i]->getIsLoaded();
			std::string type=itemsList[i]->getType();
			if(type=="Chest"){
				chest* ch=dynamic_cast<chest*>(itemsList[i]);
				if(!ch->getIsOpen()){
					ch->open();
					break;
				}//end if
			}//end if (type chest)
			if(itemLoaded&&(type=="Item"||type=="DamageTrap")){
				//get Item
				if(itemsList[i]->getIsLoaded())
					itemsList[i]->setIsLoaded(false);
				break;
			}//end if
		}//end if (distance <80)
	}//end for loop
}//end of react







