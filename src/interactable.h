#pragma once
#ifndef SRC_INTERACTABLE_H_
#define SRC_INTERACTABLE_H_
#include "entity.h"
class interactable
{
private:
	bool isLoaded;
	std::string message;
	sf::Sprite  sprite;
	sf::Image image;
	sf::Texture tx;
	std::string type;

public:
	explicit interactable(std::string img, std::string message,std::string type);
	virtual std::string getType();
	virtual ~interactable();
	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow & renderWindow);
	virtual void setPosition(float x, float y);
	virtual void setPosition(sf::Vector2f pos);
	virtual sf::Vector2f getPos();
	virtual void inspect();
	virtual void setMessage(std::string m);
	virtual sf::Sprite& getSprite();
	virtual bool getIsLoaded();
	virtual void setIsLoaded(bool isLoaded);
};




#endif /* SRC_INTERACTABLE_H_ */
