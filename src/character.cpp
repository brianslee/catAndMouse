//
//  alien.cpp
//  Attack_48
//
//  Created by James wang on 2/10/17.
//  Copyright © 2017 James wang. All rights reserved.
//
#include "character.h"
#include "trap.h"
#include "locker.h"
#include "Table.h"

Character::Character(sf::Vector2i initPos, int v, int s)
{
    rect.setSize(sf::Vector2f(40, 40));
    //rect.setPosition(280, 440);
    rect.setFillColor(sf::Color::Blue);
    //initPos = sf::Vector2i(0, 0);
	position = initPos;
	updateCoor();
	speed = v;
	originalSpeed=speed;
	sight = s;
	isLoaded=true;
	canRotate=true;
	canAttack=true;
}

void Character::update()
{
    sprite.setPosition(rect.getPosition());
}
 

void Character::setPos(const sf::Vector2f& pos)
{
	sprite_original.setPosition(pos);
    rect.setPosition(pos);
}

sf::Sprite& Character::getSprite()
{
    return sprite_original;
}
sf::Vector2i Character::getCoor()
{
    return position;
}

float Character::getAngle(sf::View& view, sf::RenderWindow& window){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f charPos = this->getPos();
	sf::Vector2f windowPos = view.getCenter();
	charPos.x += 30;
	charPos.y += 30;
	windowPos.x -= 400;
	windowPos.y -= 400;

	float angle = (-atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159) -90;
	return angle;
}

int Character::getSpeed()
{
    return speed;
}

int Character::getOriginalSpeed()
{
	return this->originalSpeed;
}
int Character::getSight()
{
    return sight;
}
sf::Vector2f Character::getPos()
{
    return sprite_original.getPosition();
}
void Character::setCoor(sf::Vector2i coor)
{
    position = coor; sprite_original.setPosition(80 * coor.x + 40, 80 * coor.y + 40);
    rect.setPosition(80 * coor.x + 40, 80 * coor.y + 40);
}
void Character::setSpeed(int v)
{
    speed = v;
}

void Character::setSpeedToOriginal(){
	this->speed=this->originalSpeed;
}

void Character::setSight(int s)
{
    sight = s;
}
void Character::updateCoor()
{
    position = sf::Vector2i(int((sprite_original.getPosition().x) / 80.0), int((sprite_original.getPosition().y) / 80.0));
}
void Character::walk(int dir) {
    //map up/down/left/right to 0/1/2/3
    updateCoor();
    switch (dir)
    {
        case 0:
            sprite_original.move(0.0, (float(speed)*(-1)));
            rect.move(0.0, (float(speed)*(-1)));
            direction = 1;
            break;
        case 1:
            sprite_original.move(0.0, (float(speed)*(1)));
            rect.move(0.0, (float(speed)*(1)));
            direction = 2;
            break;
        case 2:
            sprite_original.move(float(speed)*(-1), 0.0);
            rect.move(float(speed)*(-1), 0.0);
            direction = 3;
            break;
        case 3:
            sprite_original.move(float(speed)*(1), 0.0);
            rect.move(float(speed)*(1), 0.0);
            direction = 4;
            break;
        default:
            break;
    }
    updateCoor();
}


HealthBar* Character::getHPBar(){
	return &(this->hp);
}

int Character::getHP(){
	return this->hp.getHP();
}

void Character::setHP(int hp){
	this->hp.setHP(hp);
	if(hp<=0)this->alive=false;
}

void Character::setHPBar(HealthBar hp){
	this->hp=hp;
}


int Character::distanceToInteractable(interactable* item){
	float x=item->getPos().x-getPos().x;
	float y=item->getPos().y-getPos().y;
	return sqrt(pow(x,2)+pow(y,2));
}
void Character::inspect(std::vector<interactable*> itemsList){
	for(unsigned int i=0;i<itemsList.size();i++){
		if(distanceToInteractable(itemsList[i])<dis){
			itemsList[i]->inspect();
		}
	}
}


std::string Character::react(std::vector<interactable*> itemsList){
	std::string reactedType="NULL";
	for(unsigned int i=0;i<itemsList.size();i++){
		if(distanceToInteractable(itemsList[i])<dis){
			bool itemLoaded=itemsList[i]->getIsLoaded();
			std::string type=itemsList[i]->getType();
			if(!itemLoaded)
				break;
			if(type=="Chest"){
				chest* ch=dynamic_cast<chest*>(itemsList[i]);
				if(!ch->getIsOpen()){
					ch->open();
					reactedType="Chest";
					break;
				}
			}//end if  chest
			if(type=="Item"){
				//get Item
				itemsList[i]->setIsLoaded(false);
				reactedType="Item";
				break;
			}//end if item
			if(type=="DamageTrap"||type=="StickyTrap"){
				trap* dt=dynamic_cast<trap*>(itemsList[i]);
				if(!dt->getIsDeployed()){
					itemsList[i]->setIsLoaded(false);
					reactedType="Trap";
					break;
				}
			}//end if damage trap
			if(type=="Locker"){
				locker* lo=dynamic_cast<locker*>(itemsList[i]);
				if(!lo->getDoorOpen())
					lo->open(this);
				else
					lo->close(this);
				reactedType="HidingPlace";
			}
			if(type=="Table"){
				Table* ta=dynamic_cast<Table*>(itemsList[i]);
				ta->hide(this);
				reactedType="HidingPlace";
			}
		}//end if (distance <80)
	}//end for loop
	return reactedType;
}//end of react

bool Character::isIsLoaded()  {
	return isLoaded;
}

void Character::setIsLoaded(bool isLoaded) {
	this->isLoaded = isLoaded;
}

bool  Character::isCanAttack() {
	return canAttack;
}

void  Character::setCanAttack(bool canAttack) {
	this->canAttack = canAttack;
}

bool  Character::isCanRotate(){
	return canRotate;
}

void  Character::setCanRotate(bool canRotate) {
	this->canRotate = canRotate;
}

//REFACTORED CODE BEGINS HERE

void Character::setCharacter(bool marine)
{
    if(marine)
    {
        spriteCounter = 0;
        spriteNum = 9;
        spriteLength = 216;
        spriteWidth = 216;
        isMarine = true;
    }
    else
    {
        spriteCounter = 0;
        spriteNum = 4;
        spriteLength = 215;
        spriteWidth = 215;
        isAlien = true;
    }
}

void Character::setupSprite(sf::Texture& texture, int x, int y)
{
	getSprite().setTexture(texture);
    getSprite().setTextureRect(sf::IntRect(0, 0, spriteLength, spriteWidth));
    getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
    getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
 	rect.move(x,y);
    getSprite().move(x,y);
}

void Character::updateRotation(sf::View& view, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f charPos = getPos();
    sf::Vector2f windowPos = view.getCenter();
    charPos.x += 30;
    charPos.y += 30;
    windowPos.x -= 400;
    windowPos.y -= 400;
    
    //	std::cout << mousePos.x << ' ' << mousePos.y << std::endl;
    //	std::cout << atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159 << std::endl;
    sf::Transform transform;
    
    getSprite().setRotation(-atan2(charPos.x - windowPos.x - mousePos.x, charPos.y - windowPos.y - mousePos.y)*180.0 / 3.14159);
}

int Character::updateSprite(sf::RenderWindow& window, sf::Clock& clock) {
    if (clock.getElapsedTime().asMilliseconds() > 100.0f) {
        getSprite().setTextureRect(sf::IntRect(0, spriteCounter*spriteWidth, spriteLength, spriteWidth));
        getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
        window.draw(sprite);
        clock.restart();
        spriteCounter = (spriteCounter + 1) % spriteNum;
    }
    return spriteCounter;
}

bool Character::checkAccess(int dir, bigMap& map)
{
	if (int(getPos().x) % 80 > 50 && int(getPos().y) % 80 > 50)return true;
    
    // Character is standing on 2 grids
    // horizontal
    else if ((int(getPos().x) % 80 > 50) && (int(getPos().y) % 80 <= 50)) {
        if (dir == 0 && (int(getPos().y) % 80 <= 35))
            return !(map.getWall(getCoor().x, getCoor().y - 1) || map.getWall(getCoor().x + 1, getCoor().y - 1));
        else if (dir == 1 && (int(getPos().y) % 80 >= 45))
            return !(map.getWall(getCoor().x, getCoor().y + 1) || map.getWall(getCoor().x + 1, getCoor().y + 1));
        else return 1;
    }
    // vertical
    else if ((int(getPos().y) % 80 > 50) && (int(getPos().x) % 80 <= 50)) {
        if (dir == 2 && (int(getPos().x) % 80 <= 45))
            return !(map.getWall(getCoor().x - 1, getCoor().y) || map.getWall(getCoor().x - 1, getCoor().y + 1));
        else if (dir == 3 && (int(getPos().x) % 80 >= 45))
            return !(map.getWall(getCoor().x + 1, getCoor().y) || map.getWall(getCoor().x + 1, getCoor().y + 1));
        else return 1;
    }
    
    // Character is standing on 1 grid
    else if (int(getPos().x) % 80 <= 35 && dir == 2)return !map.getWall(getCoor().x - 1, getCoor().y);
    else if (int(getPos().x) % 80 >= 45 && dir == 3)return !map.getWall(getCoor().x + 1, getCoor().y);
    else if (int(getPos().y) % 80 <= 35 && dir == 0)return !map.getWall(getCoor().x, getCoor().y - 1);
    else if (int(getPos().y) % 80 >= 45 && dir == 1)return !map.getWall(getCoor().x, getCoor().y + 1);
    
    return 1;
}

bool Character::getIsMarine()
{
    return isMarine;
}

bool Character::getIsAlien()
{
    return isAlien;
}

int Character::getSpriteCounter()
{
    return spriteCounter;
}

int Character::getSpriteNum()
{
    return spriteNum;
}

int Character::getSpriteLength()
{
    return spriteLength;
}

int Character::getSpriteWidth()
{
    return spriteWidth;
}
/*
void Character::upgradeSprite(sf::Texture& texture, int nSpriteCounter, int nSpriteNum, int nSpriteWidth, int nSpriteLength, bool term)
{
    spriteCounter = nSpriteCounter;
    spriteNum = nSpriteNum;
    spriteWidth = nSpriteWidth;
    spriteLength = nSpriteLength;
    bool isTerm = term;

    getSprite().setTexture(texture);
    getSprite().setTextureRect(sf::IntRect(0, 0, spriteLength, spriteWidth));
    getSprite().setScale(78.0 / (double)(spriteLength), 78.0 / (double)(spriteWidth));
    getSprite().setOrigin(sf::Vector2f(spriteLength/2, spriteWidth/2));
}*/
