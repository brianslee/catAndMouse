#include "Interactable.h"
Interactable::Interactable(std::string img, std::string message,std::string type){
	this->type=type;
	this->load(img);
	this->message=message;
	isLoaded=true;
}

std::string Interactable::getType(){
	return type;
}

Interactable::~Interactable(){

	}


 void Interactable::load(std::string filename){
	std::cout<<"Loading "+filename<<std::endl;
	image.loadFromFile(filename);
	tx.loadFromImage(image);
	sprite.setTexture(tx);
}

 void Interactable::draw(sf::RenderWindow & renderWindow){
	if(isLoaded)
		renderWindow.draw(sprite);
}

 void Interactable::setPosition(float x, float y){
	sprite.setPosition(x,y);
}

 void Interactable::setPosition(sf::Vector2f pos){
	sprite.setPosition(pos);
}

 sf::Vector2f Interactable::getPos(){
	return sprite.getPosition();
}

 void Interactable::inspect(){
	if(isLoaded)
		std::cout<<"Inspect around:" + message<<std::endl;
}

 void Interactable::setMessage(std::string m){
	this->message=m;
}

 sf::Sprite& Interactable::getSprite(){
	return sprite;
}

 bool Interactable::getIsLoaded(){
	return isLoaded;
}

 void Interactable::setIsLoaded(bool isLoaded){
	this->isLoaded=isLoaded;
}
//	 float distanceToCharacter(Human a){
//		float x=a.getPos().x-this->getPos().x;
//		float y=a.getPos().y-this->getPos().y;
//		return sqrt(pow(x,2)+pow(y,2));
////		return 0;
//	}


