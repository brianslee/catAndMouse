#pragma once
#ifndef SRC_INTERACTABLE_H_
#define SRC_INTERACTABLE_H_
#include "entity.h"
class interactable
{
protected:
	bool isLoaded; // if the items should loaded up on the windows
	std::string message; //message for inspect function in character
	sf::Sprite  sprite; // sprite of the interactable
	sf::Image image; // image of the interactable
	sf::Texture tx; // texture of the interactable
	std::string type; // type of the interactable (e.g. chest/item/trap...)
	sf::IntRect rect;
	sf::Clock clock;
	float scaleFactor;


public:
	int spriteX,spriteY;
	int curGridX,curGridY;
	explicit interactable(std::string img, std::string message,std::string type); //constructor
	explicit interactable(std::string img, std::string message,std::string type,float scale); //constructor
	virtual std::string getType(); // return the type of the interactable
	virtual ~interactable();
	virtual void load(std::string filename); // load the image
	virtual void setRect(int left,int top,int width,int height);
	virtual void draw(sf::RenderWindow & renderWindow); // draw the sprite to the window
	virtual void updateSprite(int gridX,int gridY);
	virtual void animation(int startGridX,int endGridX,int startGridY, int endGridY,bool rowFirst,float freq);
	virtual void setPosition(float x, float y); //set position of the interactable args: float
	virtual void setPosition(sf::Vector2f pos); //set position of the interactable args: sf::Vector2f
	virtual sf::Vector2f getPos(); //return the position of the interactable for distance calc
	virtual sf::Vector2f getSpritePos();// return the pos of the sprite
	virtual void inspect(); // inspect the interactable, which will gives a message
	virtual void setMessage(std::string m); //set the message
	virtual sf::Sprite& getSprite(); //return the sprite of the interactable
	virtual bool getIsLoaded(); // return the boolean of the interactable is loaded or not
	virtual void setIsLoaded(bool isLoaded); // set the interactable is loaded or not
};




#endif /* SRC_INTERACTABLE_H_ */
